#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Odometry_Tests
#define _USE_MATH_DEFINES
#include <boost/test/unit_test.hpp>
#include <memory>
#include <cmath>
#include "OdometryManager.h"
#include "TwoWheelOdometryManager.h"
#include "Encoder.h"
#include "RotaryEncoder.h"
#include "MockEncoder.h"

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

BOOST_AUTO_TEST_CASE(TestGetLinearVelocity) {
    std::shared_ptr<MockEncoder> leftEncoder(new MockEncoder);
    std::shared_ptr<MockEncoder> rightEncoder(new MockEncoder);
    
    leftEncoder->SetFrequency(1.5);
    rightEncoder->SetFrequency(1.5);

    BOOST_CHECK_EQUAL(leftEncoder->GetFrequency(), 1.5);
    TwoWheelOdometryManager odometryManager(100, 50, leftEncoder.get(), rightEncoder.get());
    
    float wheelCircumference = 2 * M_PI * 50;
    // implement unicylce model. v = R/2(v_l + v_r)

    // going straight
    for(float i = 0; i < 2; i += 0.1) {
        leftEncoder->SetFrequency(i);
        rightEncoder->SetFrequency(i);
        float leftSpeed = leftEncoder->GetFrequency() * wheelCircumference;
        float rightSpeed = rightEncoder->GetFrequency() * wheelCircumference;
        int speedShouldBe = 50/2 * (leftSpeed + rightSpeed);

        BOOST_CHECK_EQUAL(speedShouldBe, odometryManager.GetLinearVelocity());
    }
}

BOOST_AUTO_TEST_CASE(TestRotaryEncoderConstructionAndInterface) {
    //RotaryEncoder has an Encoder interface
    Encoder* encoder = new RotaryEncoder(0);

    //should be able to call these methods
    encoder->GetFrequency();
}
    
BOOST_AUTO_TEST_SUITE_END()
