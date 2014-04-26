#ifndef PID_CONTROLLED_MOTOR_H
#define PID_CONTROLLED_MOTOR_H
#include "Motor.h"

class Encoder;

class PIDControlledMotor 
{
public:
    PIDControlledMotor(const unsigned int wheelRadius, const Motor motor, const Encoder* encoder);
    void SetVelocity(const int velocity);
    void Update();
private:
    /* data */
};


#endif /* end of include guard: PID_CONTROLLED_MOTOR_H */
