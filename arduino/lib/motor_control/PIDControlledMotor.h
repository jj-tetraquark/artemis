#ifndef PID_CONTROLLED_MOTOR_H
#define PID_CONTROLLED_MOTOR_H
#include "Motor.h"

class Encoder;

class PIDControlledMotor 
{
public:
    PIDControlledMotor(const unsigned int wheelRadius, const Motor& motor, Encoder* const encoder);
    void SetVelocity(const float velocity) { m_targetVelocity = velocity; }
    void Update();

private:
    const float     m_wheelCircumference;
    Motor           m_motor;
    Encoder* const  m_encoder;

    float           m_targetVelocity;
    float           m_previousError;
    float           m_errorIntegral;
    float           m_errorDerivative;
    const float     m_proportionalGain;
    const float     m_derivativeGain;
    const float     m_integralGain;

};


#endif /* end of include guard: PID_CONTROLLED_MOTOR_H */
