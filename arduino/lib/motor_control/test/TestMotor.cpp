#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MotorTest
#include <boost/test/unit_test.hpp>
#include <Arduino.h>
#include "Motor.h"

struct ArduinoSetup
{
    ArduinoSetup() {
        clear_pins();
    }
    ~ArduinoSetup() {
        clear_pins();
    }
};

BOOST_FIXTURE_TEST_SUITE(MotorTests, ArduinoSetup)

BOOST_AUTO_TEST_CASE(TestConstruction) {
    // Pins should not be initialized at first
    BOOST_CHECK(!ArduinoUno.DigitalPins[1].IsInitialized());
    BOOST_CHECK(!ArduinoUno.DigitalPins[2].IsInitialized());
    
    // Create a motor object with speed pin and direction pin
    Motor testMotor(1, 2);
    // Check it initializes pins
    BOOST_CHECK(ArduinoUno.DigitalPins[1].IsInitialized());
    BOOST_CHECK(ArduinoUno.DigitalPins[2].IsInitialized());
    
    // Should throw an exception if invalid pins 
    // - more a check of the mocks than of expected behaviour
    BOOST_CHECK_THROW(Motor(25, 60), NoSuchPinException);
}

BOOST_AUTO_TEST_CASE(TestMotorDirectionControl) {
    Motor testMotor(2, 3);

    uint8_t initialDirection = ArduinoUno.DigitalPins[2].GetValue();
    testMotor.ChangeDirection();
    uint8_t changedDirection = ArduinoUno.DigitalPins[2].GetValue();
    BOOST_CHECK_NE(initialDirection, changedDirection);
    
    // Forwards is LOW
    testMotor.SetDirectionForwards();
    BOOST_CHECK_EQUAL(ArduinoUno.DigitalPins[2].GetValue(), LOW);

    // Backwards is HIGH
    testMotor.SetDirectionBackwards();
    BOOST_CHECK_EQUAL(ArduinoUno.DigitalPins[2].GetValue(), HIGH);
}

BOOST_AUTO_TEST_CASE(TestMotorSetSpeed) {
    Motor testMotor(2, 3);
    BOOST_CHECK_EQUAL(ArduinoUno.DigitalPins[3].GetValue(), 0x0);

    for(int i = 0; i <= 100; i++) {
        testMotor.SetSpeed(i);
        int expectedValue = 255*(float(i)/100);
        BOOST_CHECK_EQUAL(ArduinoUno.DigitalPins[3].GetValue(), expectedValue);
    }
}

BOOST_AUTO_TEST_CASE(TestMotorSetSpeedWrapAround) {
    Motor testMotor(2, 3);

    testMotor.SetSpeed(-42);
    BOOST_CHECK_EQUAL(ArduinoUno.DigitalPins[3].GetValue(), 0);
    testMotor.SetSpeed(500);
    BOOST_CHECK_EQUAL(ArduinoUno.DigitalPins[3].GetValue(), 255);
}

BOOST_AUTO_TEST_SUITE_END();


BOOST_AUTO_TEST_SUITE(TestTwoWheelMotorController)

BOOST_AUTO_TEST_CASE(TwoWheelMotorControllerInheritsFromBaseClass) {
    MotorController testController = new TwoWheelMotorController;
}

BOOST_AUTO_TEST_SUITE_END();
