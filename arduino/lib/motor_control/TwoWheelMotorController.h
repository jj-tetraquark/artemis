#ifndef TWOWHEELMOTORCONTROLLER_H
#define TWOWHEELMOTORCONTROLLER_H

#include "MotorController.h"

class FeedbackControlledMotor;

class TwoWheelMotorController : public MotorController {
public:
    TwoWheelMotorController
        (FeedbackControlledMotor* const left, 
         FeedbackControlledMotor* const right,
         const int width);

    void SetVelocities(const int linearVelocity, const float angularVelocity);
    void OnTick();

private:
    const int m_axelWidth;

    FeedbackControlledMotor* const m_leftMotor;
    FeedbackControlledMotor* const m_rightMotor;
};

#endif /* end of include guard: TWOWHEELMOTORCONTROLLER_H */
