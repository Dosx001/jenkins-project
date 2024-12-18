#define BOOST_TEST_MODULE MathTestSuite
#include "math.hpp"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_add) {
  BOOST_TEST(add(1, 2) == 3);
  BOOST_TEST(add(-1, -2) == -3);
  BOOST_TEST(add(0, 0) == 0);
}

BOOST_AUTO_TEST_CASE(test_sub) {
  BOOST_TEST(sub(1, 2) == -1);
  BOOST_TEST(sub(-1, -2) == 1);
  BOOST_TEST(sub(0, 0) == 0);
}

BOOST_AUTO_TEST_CASE(test_mul) {
  BOOST_TEST(mul(1, 2) == 2);
  BOOST_TEST(mul(-1, 2) == -2);
  BOOST_TEST(mul(0, 2) == 0);
}

BOOST_AUTO_TEST_CASE(test_divi) {
  BOOST_TEST(divi(4, 2) == 2);
  BOOST_TEST(divi(1, 2) == 0);
  BOOST_CHECK_THROW(divi(1, 0), std::runtime_error);
}
