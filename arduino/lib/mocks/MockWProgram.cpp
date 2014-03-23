/*
 * MockWProgram.cpp
 *
 *  Created on: Oct 4, 2011
 *      Author: nick
 */

#include "MockWProgram.hpp"

/*
 * Mock functions for the various Arduino features.
 * To use the mocks, you can assign to or inspect the values of both
 * digital_pins and analog_pins. Note that delay does nothing.
 */

uint8_t digital_pins[14] = { 0x00 };
float analog_pins[6] = { 0.0 };

void clear_pins(void){
	digital_pins[14] = { 0x00 };
	analog_pins[6] = { 0.0 };
}

void pinMode(uint8_t pin, uint8_t mode) {
	if (pin < 0 || pin > 13) {
		throw NoSuchPinException(pin);
	}
	if (mode != OUTPUT && mode != INPUT) {
		throw InvalidPinValueException();
	}
}

void digitalWrite(uint8_t pin, uint8_t level) {
	if (pin < 0 || pin > 13) {
		throw NoSuchPinException(pin);
	}
	if (level != LOW && level != HIGH) {
		throw InvalidPinValueException();
	}
	digital_pins[pin] = level;
}

float analogRead(uint8_t pin) {
	return analog_pins[pin];
}

void delay(uint32_t delay) {
	// Does nothing.
}
