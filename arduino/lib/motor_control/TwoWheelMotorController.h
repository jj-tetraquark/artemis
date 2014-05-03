#ifndef TWOWHEELMOTORCONTROLLER_H
#define TWOWHEELMOTORCONTROLLER_H

#include "MotorController.h"

class FeedbackControlledMotor;

class TwoWheelMotorController : public MotorController {
public:
    TwoWheelMotorController
        (FeedbackControlledMotor* const left, FeedbackControlledMotor* right);

    void SetLinearVelocity(const int velocity);
    void SetAngularVelocity(const float angularVelocity);
private:
    /* data */
};

#endif /* end of include guard: TWOWHEELMOTORCONTROLLER_H */
