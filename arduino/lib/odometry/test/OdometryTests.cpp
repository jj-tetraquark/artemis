#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Odometry_Tests
#include <boost/test/unit_test.hpp>
#include "OdometryManager.h"
#include "TwoWheelOdometryManager.h"
#include "Encoder.h"
#include "RotaryEncoder.h"

BOOST_AUTO_TEST_SUITE(TestOdometry)

BOOST_AUTO_TEST_CASE(TestOdometryManagerContructionAndInterface) {
    // TwoWheelOdometryManager expects two encoders and dimensions for the robot.
    // It should also be useable through the generic OdometryManager interface

    OdometryManager* odoManager = new TwoWheelOdometryManager(1,1, new RotaryEncoder(0), new RotaryEncoder(1));
    // should be able to call these methods
    odoManager->GetLinearVelocity();
    odoManager->GetAngularVelocity();
    delete odoManager;
}

BOOST_AUTO_TEST_CASE(TestRotaryEncoderConstructionAndInterface) {
    //RotaryEncoder has an Encoder interface
    Encoder* encoder = new RotaryEncoder(0);

    //should be able to call these methods
    encoder->GetFrequency();
}
    
BOOST_AUTO_TEST_SUITE_END()
