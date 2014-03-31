#ifndef TWO_WHEEL_ODOMETRY_MANAGER_H
#define TWO_WHEEL_ODOMETRY_MANAGER_H
#include "OdometryManager.h"


class TwoWheelOdometryManager : public OdometryManager
{
public:
    virtual int GetLinearVelocity();
    virtual float GetAngularVelocity();

private:
    /* data */
};

#endif /* end of include guard: TWO_WHEEL_ODOMETRY_MANAGER */
