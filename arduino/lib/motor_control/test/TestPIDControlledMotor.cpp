#include <boost/test/unit_test.hpp>
#include "PIDControlledMotor.h"
#include "RotaryEncoder.h"

BOOST_AUTO_TEST_SUITE(TestPIDControlledMotor)

BOOST_AUTO_TEST_CASE(TestPIDControlledMotorConstructor) {
    PIDControlledMotor testControlledMotor(new RotaryEncoder<LEFT>(4,5,6));
}

BOOST_AUTO_TEST_SUITE_END();
