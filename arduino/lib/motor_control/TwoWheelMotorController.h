#ifndef TWOWHEELMOTORCONTROLLER_H
#define TWOWHEELMOTORCONTROLLER_H

#include "MotorController.h"

template<typename PIDMotor>
class TwoWheelMotorController : public MotorController {
public:
    void SetLinearVelocity(const int velocity);
    void SetAngularVelocity(const float angularVelocity);
private:
    /* data */
};

#include "TwoWheelMotorController.hpp"
#endif /* end of include guard: TWOWHEELMOTORCONTROLLER_H */
