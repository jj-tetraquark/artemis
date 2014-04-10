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

TwoWheelOdometryManager::TwoWheelOdometryManager
    (int width, int wheelRadius, const std::shared_ptr<Encoder>& leftEncoder, const std::shared_ptr<Encoder>& rightEncoder)
    : m_width(width), 
      m_wheelRadius(wheelRadius), 
      m_leftEncoder(leftEncoder), 
      m_rightEncoder(rightEncoder),
      m_wheelCircumference(2 * M_PI * wheelRadius) {
}

int TwoWheelOdometryManager::GetLinearVelocity() const {
    return 1/2.0 * (LeftWheelVelocity() + RightWheelVelocity());
}

float TwoWheelOdometryManager::GetAngularVelocity() const {
    return 1.0/m_width * (LeftWheelVelocity() - RightWheelVelocity());
}

float TwoWheelOdometryManager::LeftWheelVelocity() const {
    return GetWheelVelocity(m_leftEncoder);
}

float TwoWheelOdometryManager::RightWheelVelocity() const {
    return GetWheelVelocity(m_rightEncoder);
}

float TwoWheelOdometryManager::GetWheelVelocity(std::shared_ptr<Encoder> encoder) const {
    float velocity = encoder->GetFrequency() * m_wheelCircumference;
    return velocity * (encoder->GetDirection() == Encoder::Direction::FORWARDS ? 1 : -1);
}
