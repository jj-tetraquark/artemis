#include "MockWProgram.hpp"

/*
 * Mock functions for the various Arduino features.
 * To use the mocks, you can assign to or inspect the values of both
 * digital_pins and analog_pins. Note that delay does nothing.
 */

// Delicious globals TT__TT
Arduino ArduinoUno;


void clear_pins(void) {
    for(auto pin : ArduinoUno.DigitalPins) {
        pin.Reset();
    }
}

void checkPinIsValid(uint8_t pin) {
	if (pin < 0 || pin > 13) {
		throw NoSuchPinException(pin);
	}
}

void pinMode(uint8_t pin, uint8_t mode) {
    checkPinIsValid(pin);
	if (mode != OUTPUT && mode != INPUT) {
		throw InvalidPinValueException();
	}
    ArduinoUno.DigitalPins[pin].SetMode(mode);
}

void digitalWrite(uint8_t pin, uint8_t level) {
    checkPinIsValid(pin);
	if (level != LOW && level != HIGH) {
		throw InvalidPinValueException();
	}
    if (!ArduinoUno.DigitalPins[pin].IsInitialized())
        throw UninitializedPinException(pin);
    ArduinoUno.DigitalPins[pin].SetValue(level);
}

void analogWrite(uint8_t pin, uint8_t level) {
    checkPinIsValid(pin);
    if (level < 0 || level > 255) {
        throw InvalidPinValueException();
    }
    ArduinoUno.DigitalPins[pin].SetValue(level);
}

float analogRead(uint8_t pin) {
	return ArduinoUno.AnalogPins[pin];
}

void delay(uint32_t delay) {
	// Does nothing.
}

void init() {}


// Pin definitions
// TODO - move out of here

Pin::Pin() {
    Reset();
}

void Pin::Reset() {
   m_initialized = false;
   m_value = 0x0;
}

void Pin::SetMode(uint8_t io) {
    m_IO = io;
    m_initialized = true;
}

void Pin::SetValue(uint8_t value) {
    m_value = value;
}
