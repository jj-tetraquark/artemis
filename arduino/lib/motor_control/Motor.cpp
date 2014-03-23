#include <Arduino.h>
#include "Motor.h"

Motor::Motor(int directionPin, int pwmPin) 
    : m_directionPin(directionPin),
      m_pwmPin(pwmPin) {
    pinMode(m_directionPin, OUTPUT);
    pinMode(m_pwmPin, OUTPUT);
}
