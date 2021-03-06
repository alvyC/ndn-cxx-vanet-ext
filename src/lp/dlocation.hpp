#ifndef NDN_CXX_DLOCATION_HPP
#define NDN_CXX_DLOCATION_HPP

#include "tlv.hpp"
#include "location.hpp"

namespace ndn {
namespace lp {

class DLocation {

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

  DLocation();

  DLocation(double, double);

  template<encoding::Tag TAG>
  size_t
  wireEncode(EncodingImpl<TAG>& encoder) const;

  // const Block&
  // wireEncode() const;

  void
  wireDecode(const Block& wire);

  double
  getLongitude() const {
    return m_longitude;
  }

  void
  setLongitude(const double lg) {
    m_longitude = lg;
  }

  double
  getLatitude() const {
    return m_latitude;
  }

  void
  setLaitude(const double lt) {
    m_latitude = lt;
  }

private:
  double m_longitude;
  double m_latitude;
};

NDN_CXX_DECLARE_WIRE_ENCODE_INSTANTIATIONS(DLocation);

}  // namespace lp
} // namespace ndn

#endif