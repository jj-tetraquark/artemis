#include <boost/test/unit_test.hpp>
#include <Arduino.h>
#include "MotorController.h"
#include "TwoWheelMotorController.h"
#include "MockPIDMotor.h"

BOOST_AUTO_TEST_SUITE(TestTwoWheelMotorController)

BOOST_AUTO_TEST_CASE(TwoWheelMotorControllerConstructionAndInterface) {
    MockPIDMotor leftMotor;
    MockPIDMotor rightMotor;
    MotorController* testController = new TwoWheelMotorController(&leftMotor, &rightMotor);
    testController->SetVelocities(30, 1.5);
    delete testController;
}

BOOST_AUTO_TEST_CASE(TestSetLinearVelocity) {
    MockPIDMotor leftMotor;
    MockPIDMotor rightMotor;
    TwoWheelMotorController motorController(&leftMotor, &rightMotor);
   
    for(int v = -10; v < 11; v++) {
        motorController.SetVelocities(v, 0);
        BOOST_CHECK_EQUAL(leftMotor.GetVelocity(), v);
        BOOST_CHECK_EQUAL(rightMotor.GetVelocity(), v);
    }
}


BOOST_AUTO_TEST_SUITE_END();
