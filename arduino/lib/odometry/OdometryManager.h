#ifndef ODOMETRY_MANAGER_H
#define ODOMETRY_MANAGER_H

class OdometryManager {
public:
    virtual int GetLinearVelocity() const = 0;
    virtual float GetAngularVelocity() const = 0;

};



#endif /* end of include guard: ODOMETRY_MANAGER_H */
