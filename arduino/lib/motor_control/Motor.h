#ifndef MOTOR_H
#define MOTOR_H
#include <stdint.h>

class Motor {
public:
    enum class Direction {
        FORWARDS,
        BACKWARDS
    };

    Motor(int directionPin, int pwmPin);

    void ChangeDirection();
    void SetDirectionForwards();
    void SetDirectionBackwards();
    void SetSpeed(int speed);
    

private:
    Direction m_direction;
    const uint8_t m_directionPin;
    const uint8_t m_pwmPin;
};

#endif // end of include guard: MOTOR_H 
