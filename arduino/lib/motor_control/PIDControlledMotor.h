#ifndef PID_CONTROLLED_MOTOR_H
#define PID_CONTROLLED_MOTOR_H
#include "Motor.h"

class Encoder;

class PIDControlledMotor 
{
public:
    PIDControlledMotor(const unsigned int wheelRadius, const Motor& motor, Encoder* const encoder);
    void SetVelocity(const int velocity) { m_targetVelocity = velocity; }
    void Update();

private:
    int             m_targetVelocity;
    const float     m_wheelCircumference;
    Motor           m_motor;
    Encoder* const  m_encoder;

};


#endif /* end of include guard: PID_CONTROLLED_MOTOR_H */
