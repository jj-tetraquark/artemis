#ifndef TWOWHEELMOTORCONTROLLER_H
#define TWOWHEELMOTORCONTROLLER_H

#include "MotorController.h"

class FeedbackControlledMotor;

class TwoWheelMotorController : public MotorController {
public:
    TwoWheelMotorController
        (FeedbackControlledMotor* const left, FeedbackControlledMotor* right);

    void SetVelocities(const int linearVelocity, const float angularVelocity);
private:
    FeedbackControlledMotor* const m_leftMotor;
    FeedbackControlledMotor* const m_rightMotor;
};

#endif /* end of include guard: TWOWHEELMOTORCONTROLLER_H */
