#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MotorTest
#include <boost/test/unit_test.hpp>
#include <Arduino.h>
#include "Motor.h"


BOOST_AUTO_TEST_SUITE(MotorTests)

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
    clear_pins();
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
    
    clear_pins();
}

BOOST_AUTO_TEST_SUITE_END()
