#ifndef PID_MOTOR_INTERFACE
#define PID_MOTOR_INTERFACE

class PIDMotorInterface 
{
public:
    virtual void SetVelocity(const float velocity) = 0;
    virtual void Update() = 0;
};


#endif /* end of include guard: PID_MOTOR_INTERFACE */
