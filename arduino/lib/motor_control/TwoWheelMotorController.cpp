#include "TwoWheelMotorController.h"
#include "FeedbackControlledMotor.h"

TwoWheelMotorController::TwoWheelMotorController
    (FeedbackControlledMotor* const left, FeedbackControlledMotor* const right)
    : m_leftMotor(left),
      m_rightMotor(right) {
}

void TwoWheelMotorController::SetVelocities
    (const int linearVelocity, const float angularVelocity) {
    m_leftMotor->SetVelocity(linearVelocity); 
    m_rightMotor->SetVelocity(linearVelocity); 
}

