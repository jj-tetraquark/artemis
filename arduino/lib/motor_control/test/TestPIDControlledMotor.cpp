#include <boost/test/unit_test.hpp>
#include <iostream>
#include <fstream>

#include "Arduino.h"
#include "PIDControlledMotor.h"
#include "RotaryEncoder.h"
#include "Motor.h"
#include "test/MockEncoder.h"

BOOST_AUTO_TEST_SUITE(TestPIDControlledMotor)

BOOST_AUTO_TEST_CASE(TestPIDControlledMotorConstructorAndInterface) {
    PIDMotorInterface* testControlledMotor = new PIDControlledMotor(20, Motor(7,8), new RotaryEncoder<LEFT>(4,5,6));
    testControlledMotor->SetVelocity(100);
    testControlledMotor->Update();
    delete testControlledMotor;
}

BOOST_AUTO_TEST_CASE(TestPIDFunction) {
    MockEncoder* testEncoder = new MockEncoder();
    const int wheelRadius = 10;
    const float wheelCircumference = 2 * M_PI * wheelRadius;

    clear_pins();

    PIDControlledMotor testControlledMotor(wheelRadius, Motor(2,3), testEncoder, 0.1, 0.1, 0.01);

    const int targetVelocity = 100;
    float currentVelocity;
    float velocitySum = 0;
    testControlledMotor.SetVelocity(targetVelocity);

    std::ofstream outputDataFile("pid_data.dat");
    
    // Simulate 600 'ticks' and let the PID controller modulate motor speed
    // should get up to speed before it reaches the end (depending on calibration)
    for(int i = 0; i < 600; i++) {
        currentVelocity = testEncoder->RevolutionsPerSecond() * wheelCircumference * testEncoder->GetDirection();
        velocitySum += currentVelocity;
        outputDataFile << i << "\t" <<  currentVelocity << std::endl;

        testControlledMotor.Update();
        int rawArduinoOutput = ArduinoUno.DigitalPins[3].GetValue();
        int motorDirection = (ArduinoUno.DigitalPins[2].GetValue() == LOW) ? 1 : -1;
        
        // convert uint8_t value to something resembling speed;
        // say 255 == 8rps on motor
        // minus some resistance as function of speed ( 0.2 * speed^2)
        float motorRPS = (rawArduinoOutput + 1) / 32.0;
        float finalRPS = motorRPS - (0.05 * pow(motorRPS, 2));
        if (finalRPS < 0) finalRPS = 0;

        testEncoder->SetRevolutionsPerSecond(finalRPS);
        testEncoder->SetDirection(static_cast<Encoder::Direction>(motorDirection));
    }

    float averageVelocity = velocitySum/600;
    BOOST_CHECK_CLOSE(currentVelocity, targetVelocity, 2);
    BOOST_CHECK_CLOSE(averageVelocity, targetVelocity, 0.5);

    outputDataFile.close();
    std::cout << "\nPID controlled motor speed over time written to pid_data.dat - open with something like gnuplot to ensure is behaving like a proper PID\n"; 
}

BOOST_AUTO_TEST_SUITE_END();
