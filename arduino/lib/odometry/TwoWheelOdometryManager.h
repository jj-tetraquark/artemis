#ifndef TWO_WHEEL_ODOMETRY_MANAGER_H
#define TWO_WHEEL_ODOMETRY_MANAGER_H
#include "OdometryManager.h"
#include "Encoder.h"


class TwoWheelOdometryManager : public OdometryManager
{
public:
    TwoWheelOdometryManager(int width, int wheelRadius, Encoder* leftEncoder, Encoder* rightEncoder);
    virtual int GetLinearVelocity();
    virtual float GetAngularVelocity();

private:
    /* data */
};

#endif /* end of include guard: TWO_WHEEL_ODOMETRY_MANAGER */
