#include <Arduino.h>
#include "Motor.h"

Motor::Motor(int directionPin, int pwmPin) 
    : m_directionPin(directionPin),
      m_pwmPin(pwmPin),
      m_direction(Direction::FORWARDS) {
    pinMode(m_directionPin, OUTPUT);
    pinMode(m_pwmPin, OUTPUT);
}

void Motor::ChangeDirection() {
    if (m_direction == Direction::FORWARDS) {
        SetDirectionBackwards();
    } else {
        SetDirectionForwards();
    }
}

void Motor::SetDirectionForwards() {
    m_direction = Direction::FORWARDS;
    digitalWrite(m_directionPin, LOW);
}

void Motor::SetDirectionBackwards() {
    m_direction = Direction::BACKWARDS;
    digitalWrite(m_directionPin, HIGH);
}
