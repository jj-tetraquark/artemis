#include <boost/test/unit_test.hpp>
#include "PIDControlledMotor.h"
#include "RotaryEncoder.h"

BOOST_AUTO_TEST_SUITE(TestPIDControlledMotor)

BOOST_AUTO_TEST_CASE(TestPIDControlledMotorConstructorAndInterface) {
    PIDControlledMotor testControlledMotor(20, new RotaryEncoder<LEFT>(4,5,6));
    testControlledMotor.SetVelocity(100);
}

BOOST_AUTO_TEST_SUITE_END();
