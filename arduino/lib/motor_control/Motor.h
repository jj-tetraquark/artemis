#ifndef MOTOR_H
#define MOTOR_H
#include <stdint.h>

class Motor {
public:
    Motor(int directionPin, int pwmPin);

private:
    uint8_t m_directionPin;
    uint8_t m_pwmPin;
};

#endif // end of include guard: MOTOR_H 
