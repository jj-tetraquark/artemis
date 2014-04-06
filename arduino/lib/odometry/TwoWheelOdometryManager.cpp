#define _USE_MATH_DEFINES
#include <cmath>
#include "TwoWheelOdometryManager.h"

TwoWheelOdometryManager::TwoWheelOdometryManager
    (int width, int wheelRadius, Encoder* leftEncoder, Encoder* rightEncoder) 
    : m_width(width), 
      m_wheelRadius(wheelRadius), 
      m_leftEncoder(leftEncoder), 
      m_rightEncoder(rightEncoder),
      m_wheelCircumference(2 * M_PI * wheelRadius) {
     
}

int TwoWheelOdometryManager::GetLinearVelocity() const {
    return m_wheelRadius/2.0 * (LeftWheelVelocity() + RightWheelVelocity());
}

float TwoWheelOdometryManager::GetAngularVelocity() const {

}

float TwoWheelOdometryManager::LeftWheelVelocity() const {
    float velocity = m_leftEncoder->GetFrequency() * m_wheelCircumference;
    return velocity * (m_leftEncoder->GetDirection() == Encoder::Direction::FORWARDS ? 1 : -1);
}

float TwoWheelOdometryManager::RightWheelVelocity() const {
    float velocity = m_rightEncoder->GetFrequency() * m_wheelCircumference;
    return velocity * (m_rightEncoder->GetDirection() == Encoder::Direction::FORWARDS ? 1 : -1);
}
