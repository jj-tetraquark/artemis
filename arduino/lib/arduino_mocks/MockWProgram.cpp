#include "MockWProgram.hpp"
#include <chrono>

/*
 * Mock functions for the various Arduino features.
 * To use the mocks, you can assign to or inspect the values of both
 * digital_pins and analog_pins. Note that delay does nothing.
 */

using namespace std::chrono;

// Delicious globals TT__TT
Arduino ArduinoUno;
volatile voidFuncPtr intFunc[EXTERNAL_NUM_INTERRUPTS];
const system_clock::time_point startTime = system_clock::now();


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

int digitalRead(uint8_t pin) {
    checkPinIsValid(pin);
    if (!ArduinoUno.DigitalPins[pin].IsInitialized())
        throw UninitializedPinException(pin);
    if (ArduinoUno.DigitalPins[pin].GetMode() != INPUT)
        throw std::logic_error("Tried to read from pin initialized to OUTPUT. (pin " + std::to_string(pin) + ")");
    return ArduinoUno.DigitalPins[pin].GetValue();
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

uint32_t millis() {
    return duration_cast<milliseconds>(system_clock::now() - startTime).count();
}

uint32_t micros() {
    return duration_cast<microseconds>(system_clock::now() - startTime).count();
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



void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode) {
  if(interruptNum < EXTERNAL_NUM_INTERRUPTS) {
    intFunc[interruptNum] = userFunc;
  }
}

void detachInterrupt(uint8_t interruptNum) {
    intFunc[interruptNum] = nullptr;
}

void testTriggerInterrupt(uint8_t interruptNum) {
    if(intFunc[interruptNum] != nullptr) {
        intFunc[interruptNum]();
    } else {
        throw InvalidValueException();
    }
}
