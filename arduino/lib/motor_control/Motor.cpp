#include <Arduino.h>
#include "Motor.h"

Motor::Motor(const int directionPin, const int pwmPin) 
    : m_directionPin(directionPin),
      m_pwmPin(pwmPin) {
    pinMode(m_directionPin, OUTPUT);
    pinMode(m_pwmPin, OUTPUT);
}

void Motor::SetDirectionForwards() {
    digitalWrite(m_directionPin, LOW);
}

void Motor::SetDirectionBackwards() {
    digitalWrite(m_directionPin, HIGH);
}

// Motor speed is taken as a percentage
void Motor::SetSpeed(int speed) {
    if(speed > 0) {
        SetDirectionForwards();
    } else {
        SetDirectionBackwards();
        speed *= -1; // abs value;
    }

    // protect against wraparound
    if (speed > 100) {
        speed = 100;
    }
    int eightBitValue = 255*(float(speed)/100);
    analogWrite(m_pwmPin, eightBitValue);
}

void Motor::Stop() {
    SetSpeed(0);
}
