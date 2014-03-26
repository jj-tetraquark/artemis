#include <boost/test/unit_test.hpp>
#include <Arduino.h>
#include "MotorController.h"
#include "TwoWheelMotorController.h"

BOOST_AUTO_TEST_SUITE(TestTwoWheelMotorController)

BOOST_AUTO_TEST_CASE(TwoWheelMotorControllerInheritsFromBaseClass) {
    MotorController* testController = new TwoWheelMotorController();
}

BOOST_AUTO_TEST_SUITE_END();
