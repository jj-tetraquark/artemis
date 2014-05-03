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
    testController->SetLinearVelocity(30);
    testController->SetAngularVelocity(2.3);
    delete testController;
}


BOOST_AUTO_TEST_SUITE_END();
