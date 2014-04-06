#define _USE_MATH_DEFINES
#include <cmath>
#include "TwoWheelOdometryManager.h"

TwoWheelOdometryManager::TwoWheelOdometryManager
    (int width, int wheelRadius, Encoder* leftEncoder, Encoder* rightEncoder) 
    : m_width(width), 
      m_wheelRadius(wheelRadius), 
      m_leftEncoder(leftEncoder), 
      m_rightEncoder(rightEncoder) {
     
}

int TwoWheelOdometryManager::GetLinearVelocity() const {
    float leftWheelSpeed = m_leftEncoder->GetFrequency() * M_PI * 2 * m_wheelRadius;
    float rightWheelSpeed = m_rightEncoder->GetFrequency() * M_PI * 2 * m_wheelRadius;
    return m_wheelRadius/2.0 * (leftWheelSpeed + rightWheelSpeed);
}

float TwoWheelOdometryManager::GetAngularVelocity() const {

}
