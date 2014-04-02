#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Odometry_Tests
#include <boost/test/unit_test.hpp>
#include "OdometryManager.h"
#include "TwoWheelOdometryManager.h"
#include "Encoder.h"
#include "RotaryEncoder.h"

BOOST_AUTO_TEST_SUITE(TestOdometry)

BOOST_AUTO_TEST_CASE(TestOdometryManagerContruction) {
    OdometryManager* odoManager = new TwoWheelOdometryManager;
    // should be able to call these methods
    odoManager->GetLinearVelocity();
    odoManager->GetAngularVelocity();
    delete odoManager;
}

BOOST_AUTO_TEST_CASE(TestRotaryEncoderConstruction) {
    //RotaryEncoder has a BaseEncoder interface
    Encoder* encoder = new RotaryEncoder;
}
    
BOOST_AUTO_TEST_SUITE_END()
