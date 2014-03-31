#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Odometry_Tests
#include <boost/test/unit_test.hpp>
#include "OdometryManager.h"

BOOST_AUTO_TEST_SUITE(TestOdometry)

BOOST_AUTO_TEST_CASE(TestOdometryManagerContruction) {
    OdometryManager odoManager;
}
    
BOOST_AUTO_TEST_SUITE_END()
