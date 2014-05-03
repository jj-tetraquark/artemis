#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

class MotorController {
public:
    virtual void SetVelocities(const int linearVelocity, const float angularVelocity) = 0;
};


#endif /* end of include guard: MOTORCONTROLLER_H */
