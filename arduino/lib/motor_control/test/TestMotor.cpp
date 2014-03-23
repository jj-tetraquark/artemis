#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MotorTest
#include <boost/test/unit_test.hpp>
#include <Arduino.h>
#include "Motor.h"


BOOST_AUTO_TEST_SUITE(MotorTests)

BOOST_AUTO_TEST_CASE(TestConstruction)
{
    // Create a motor object with speed pin and direction pin
    Motor testMotor(1, 2);
    // Should throw an exception if invalid pins
    BOOST_CHECK_THROW(Motor(25, 60), NoSuchPinException)
}


BOOST_AUTO_TEST_SUITE_END()
