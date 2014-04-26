#include "Arduino.h"
#include "PIDControlledMotor.h"
#include "Encoder.h"

PIDControlledMotor::PIDControlledMotor
    (const unsigned int wheelRadius, const Motor& motor, Encoder* const encoder)
    : m_wheelCircumference(2 * PI * wheelRadius), m_motor(motor), m_encoder(encoder) {
}

void PIDControlledMotor::Update() {

}
