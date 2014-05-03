#include <boost/test/unit_test.hpp>
#include <Arduino.h>
#include "MotorController.h"
#include "TwoWheelMotorController.h"
#include "MockPIDMotor.h"

BOOST_AUTO_TEST_SUITE(TestTwoWheelMotorController)

BOOST_AUTO_TEST_CASE(TwoWheelMotorControllerConstructionAndInterface) {
    MockPIDMotor leftMotor;
    MockPIDMotor rightMotor;
    MotorController* testController = new TwoWheelMotorController(&leftMotor, &rightMotor, 10);
    testController->SetVelocities(30, 1.5);
    testController->OnTick();
    delete testController;
}

BOOST_AUTO_TEST_CASE(TestSetVelocities) {
    MockPIDMotor leftMotor;
    MockPIDMotor rightMotor;
    const int axelWidth = 10;
    TwoWheelMotorController motorController(&leftMotor, &rightMotor, axelWidth);
   
    for(int v = -10; v < 11; v++) {
        for(int w_int = -30; w_int < 31; w_int += 1) {
            float w = w_int/10.0;
            motorController.SetVelocities(v, w);
            
            float v_l = leftMotor.GetVelocity();
            float v_r = rightMotor.GetVelocity();
            // V = 1/2 (v_r + v_l)
            // W = 1/L (v_r - v_l)
            
            float V = 0.5 * (v_r + v_l);
            float W = (1.0/axelWidth) * (v_r - v_l);

            BOOST_CHECK_CLOSE(v, V, 0.1);
            BOOST_CHECK_CLOSE(w, W, 0.1);
        }
    }
}

BOOST_AUTO_TEST_CASE(TestOnTick) {
    // On commander tick, motor controller should call Update() on its motors
    MockPIDMotor leftMotor;
    MockPIDMotor rightMotor;
    const int axelWidth = 10;
    TwoWheelMotorController motorController(&leftMotor, &rightMotor, axelWidth);

    BOOST_CHECK_EQUAL(leftMotor.GetUpdateCallCount(), 0);
    BOOST_CHECK_EQUAL(rightMotor.GetUpdateCallCount(), 0);

    motorController.OnTick();

    BOOST_CHECK_EQUAL(leftMotor.GetUpdateCallCount(), 1);
    BOOST_CHECK_EQUAL(rightMotor.GetUpdateCallCount(), 1);
}


BOOST_AUTO_TEST_SUITE_END();
