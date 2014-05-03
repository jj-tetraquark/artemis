#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

class MotorController {
public:
    virtual void SetLinearVelocity(const int velocity) = 0;
    virtual void SetAngularVelocity(const float angularVelocity) = 0;
};


#endif /* end of include guard: MOTORCONTROLLER_H */
