#include "TwoWheelMotorController.h"
#include "FeedbackControlledMotor.h"

TwoWheelMotorController::TwoWheelMotorController
    (FeedbackControlledMotor* const left, 
     FeedbackControlledMotor* const right, 
     const int width)
    : m_leftMotor(left),
      m_rightMotor(right),
      m_axelWidth(width) {
}

void TwoWheelMotorController::SetVelocities
    (const int linearVelocity, const float angularVelocity) {
    // Solve linear and angular simultaneously
    // v_r = V + wL/2
    float v_r = linearVelocity + (angularVelocity * m_axelWidth)/2;
    float v_l = 2 * linearVelocity - v_r;

    m_leftMotor->SetVelocity(v_l);
    m_rightMotor->SetVelocity(v_r);
}

