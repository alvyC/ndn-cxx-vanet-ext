#include "lp/plocation.hpp"
#include "lp/dlocation.hpp"

#include "boost-test.hpp"
#include "make-interest-data.hpp"

namespace ndn {
namespace lp {
namespace tests {

using namespace ndn::tests;

BOOST_AUTO_TEST_SUITE(Lp)
BOOST_AUTO_TEST_SUITE(TestLocation)

BOOST_AUTO_TEST_CASE(GetLongitudeLatitude)
{
  // double longitude = 10.1;
  // double latitude = 20.2;

  // Location lc1(10.1, 20.2);

  // BOOST_CHECK_EQUAL(lc1.getLatitude(), latitude);
  // BOOST_CHECK_EQUAL(lc1.getLongitude(), longitude);
}

BOOST_AUTO_TEST_CASE(Encode)
{
  // Location lc(10.1, 20.2);

  // Block wire;
  // BOOST_REQUIRE_NO_THROW(wire = lc.wireEncode());

  // for (Buffer::const_iterator it = wire.begin(); it != wire.end(); ++it) {
  //   printf("0x%02x", *it);
  // }
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

}
}
}