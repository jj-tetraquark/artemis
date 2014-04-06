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
    int m_width;
    int m_wheelRadius;
    std::shared_ptr<Encoder> m_leftEncoder;
    std::shared_ptr<Encoder> m_rightEncoder;
};

#endif /* end of include guard: TWO_WHEEL_ODOMETRY_MANAGER */
