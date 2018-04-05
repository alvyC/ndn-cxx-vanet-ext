#ifndef NDN_CXX_LOCATION_HPP
#define NDN_CXX_LOCATION_HPP

#include "../data.hpp"

namespace ndn {
namespace lp {

class Location {

public:
class Error : public ndn::tlv::Error
{
public:
  explicit
  Error(const std::string& what)
    : ndn::tlv::Error(what)
  {
  }
};

  enum {
    Double = 134,
    Longitude = 135,
    Latitude = 136
  };

  Location();

  Location(double, double);

  template<encoding::Tag TAG>
  size_t
  wireEncode(EncodingImpl<TAG>& encoder) const;

  void
  wireDecode(const Block& wire);

  double
  getLongitude() const {
    return m_longitude;
  }

  double
  getLatitude() const {
    return m_latitude;
  }

private:
  double m_longitude;
  double m_latitude;
};

}
}

#endif