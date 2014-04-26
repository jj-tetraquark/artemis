#ifndef PID_CONTROLLED_MOTOR_H
#define PID_CONTROLLED_MOTOR_H

#include "Encoder.h"

class PIDControlledMotor 
{
public:
    PIDControlledMotor(const unsigned int wheelRadius, const Encoder* encoder);
    void SetVelocity(const int velocity);
private:
    /* data */
};


#endif /* end of include guard: PID_CONTROLLED_MOTOR_H */
