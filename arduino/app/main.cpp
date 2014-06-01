#include <Arduino.h>
#include "PIDControlledMotor.h"
#include "TwoWheelOdometryManager.h"
#include "TwoWheelMotorController.h"
#include "RotaryEncoder.h"
#include "Config.h"

RotaryEncoder<LEFT> leftEncoder(Config::Pins::LEFT_ENCODER_A, 
                                Config::Pins::LEFT_ENCODER_B, 
                                Config::ROTARY_ENCODER_RATIO);

RotaryEncoder<RIGHT> rightEncoder(Config::Pins::RIGHT_ENCODER_A,
                                  Config::Pins::RIGHT_ENCODER_B,
                                  Config::ROTARY_ENCODER_RATIO);

PIDControlledMotor leftMotor(Config::Dimensions::WHEEL_RADIUS, 
                             Motor(Config::Pins::LEFT_MOTOR_DIRECTION, Config::Pins::LEFT_MOTOR_SPEED),
                             &leftEncoder);

PIDControlledMotor rightMotor(Config::Dimensions::WHEEL_RADIUS,
                              Motor(Config::Pins::RIGHT_MOTOR_DIRECTION, Config::Pins::RIGHT_MOTOR_SPEED),
                              &rightEncoder);

TwoWheelMotorController motorController(&leftMotor, &rightMotor, Config::Dimensions::ROBOT_WIDTH);

void loop() {
    motorController.OnTick();
}

int main()
{
    motorController.SetVelocities(10, 0.2); // This should make the robot drive in a circle
    init();
    while(true)
        loop();
    return 0;
}
