/*
   Ardutest - An Arduino mocks library for unit testing.  

   Copyright (C) 2011 Mind Studios, Inc.

   This library is free software; you can redistribute it and/or modify it
   under the terms of the GNU Lesser General Public License as published by the
   Free Software Foundation; either version 2.1 of the License, or (at your
   option) any later version.

   This library is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
   for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this library; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

   Mind Studios, Inc., hereby disclaims all copyright interest in the library
   Ardutest (an Arduino mocks library for unit testing) written by Nick
   Pascucci.
   */

/*!
  \file
  Mock version of WProgram.h for development machine unit testing.
  */

#ifndef MOCKWPROGRAM_H_
#define MOCKWPROGRAM_H_

#include "inttypes.h"
#include <string>
#include <stdexcept>

// Compiler warning to indicate test header being used to catch include errors.
// Remove this if you're confident everything works as planned.
#warning Using mock WProgram.h file.

// Arduino definitions.
#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1

#define true 0x1
#define false 0x0

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

#define INTERNAL 3
#define DEFAULT 1
#define EXTERNAL 0

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))
// We use the standard definition of abs() rather than the Arduino one.

#define interrupts() sei()
#define noInterrupts() cli()

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

/*
   Mock Arduino functions. 
   */

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t level);
float analogRead(uint8_t pin);

//TODO - implement
void delay(uint32_t millis);

//TODO - implement
void randomSeed(float seed);

//TODO - implement
uint32_t random(uint32_t max);

void clear_pins();

class Pin {
public:
    Pin(); 
    void     SetMode(uint8_t io); // really this should be an enum;
    void     SetValue(uint8_t newValue);
    void     Reset();
    uint8_t  GetValue() { return m_value; }
    bool     IsInitialized() { return m_initialized; }
     
private:
    bool     m_initialized;
    uint8_t  m_IO;        
    uint8_t  m_value; // can be HIGH, LOW or 0 - 255 depending on if pwm
};

struct Arduino {
    Pin DigitalPins[14];
    float AnalogPins[6]; // TODO - make an AnalogPin class
};


class MockSerial {
public:
    // The output buffer array.
    uint8_t * _out_buf;

    // The next open output buffer position.
    uint16_t _out_ptr;

    // The input buffer array.
    uint8_t * _in_buf;

    // The next input buffer position which will be returned by a call to read().
    uint16_t _in_ptr;

    // The current baud rate.
    uint32_t _baud;

    // The size of the input data.
    uint16_t _size;

    /*!
      \brief Set the input buffer data.

      \param new_buf A pointer to a byte array containing the input data.
      \param size The size of the input array.
      */
    void set_input_buffer(uint8_t * new_buf, uint16_t size);

    //brief Reset the serial buffers.
    void reset(void);

    // These form the primary interface for Serial.
    // Creates a new mock serial buffer with its own buffer.
    MockSerial();

    // End the serial communications. This is a no-op.
    void end(void);

    /*!
      \brief Begin serial communications. 

      This sets the current baud rate, but is otherwise a no-op.

      \param baud The baud rate to communicate at.
      */
    void begin(uint32_t baud);

    /*!
      \brief \brief Check the number of bytes available in the input buffer.

      \return The number of bytes available for read.
      */
    uint32_t available();

    /*!
      \brief Read a byte from the input buffer.

      \return The next byte from the input buffer.
      */
    int read();

    /*!
      \brief Write a byte to the output buffer.

      \param value The byte to write.
      */
    void write(uint8_t value);

    /*!
      \brief Write a byte array to the output buffer.

      \param values An array of values to write.
      \param length The length of the array.
      */
    void write(uint8_t * values, uint32_t length);
};

/*
 * These variables allow you to inspect and set the MCU state in tests.
 */

// Shared Serial object.
extern MockSerial Serial;

extern Arduino ArduinoUno;

struct NoSuchPinException : public std::logic_error {
    NoSuchPinException(int pinNumber) : std::logic_error("Pin " + std::to_string(pinNumber) +  " does not exist")
    {}
};

struct InvalidPinValueException : public std::logic_error {
    InvalidPinValueException() : std::logic_error("Invalid pin value")
    {}
};

struct UninitializedPinException : public std::logic_error {
    UninitializedPinException(int pinNumber) : std::logic_error("Tried to read/write to pin uninitialized pin " + std::to_string(pinNumber))
    {}
};

#endif /* MOCKWPROGRAM_H_ */
