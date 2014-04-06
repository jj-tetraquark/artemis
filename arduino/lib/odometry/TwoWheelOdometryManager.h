#ifndef TWO_WHEEL_ODOMETRY_MANAGER_H
#define TWO_WHEEL_ODOMETRY_MANAGER_H
#include <memory>
#include "OdometryManager.h"
#include "Encoder.h"


class TwoWheelOdometryManager : public OdometryManager
{
public:
    TwoWheelOdometryManager(int width, int wheelRadius, Encoder* leftEncoder, Encoder* rightEncoder);
    virtual int GetLinearVelocity() const;
    virtual float GetAngularVelocity() const;

private:
    float LeftWheelVelocity() const;
    float RightWheelVelocity() const;
    float GetWheelVelocity(std::shared_ptr<Encoder> encoder) const;

    int m_width;
    int m_wheelRadius;
    float m_wheelCircumference;
    std::shared_ptr<Encoder> m_leftEncoder;
    std::shared_ptr<Encoder> m_rightEncoder;
};

#endif /* end of include guard: TWO_WHEEL_ODOMETRY_MANAGER */
