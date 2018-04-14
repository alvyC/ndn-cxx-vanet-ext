#include "dlocation.hpp"


namespace ndn {
namespace lp {

DLocation::DLocation() = default;

DLocation::DLocation(double longitude, double latitude)
  : m_longitude(longitude)
  , m_latitude(latitude)
  {
  }

template<encoding::Tag TAG>
size_t
DLocation::wireEncode(EncodingImpl<TAG>& encoder) const
{
  std::cout << "DLocation wireEncode()" << std::endl;
  size_t totalLength = 0;
  size_t doubleLength = 10;

  const uint8_t* longitudeBytes = reinterpret_cast<const uint8_t*>(&m_longitude);
  totalLength += encoder.prependByteArrayBlock(ndn::lp::location::Double, longitudeBytes, 8);
  totalLength += encoder.prependVarNumber(doubleLength);
  totalLength += encoder.prependVarNumber(ndn::lp::location::Longitude);

  const uint8_t* latitudeBytes = reinterpret_cast<const uint8_t*>(&m_latitude);
  totalLength += encoder.prependByteArrayBlock(ndn::lp::location::Double, latitudeBytes, 8);
  totalLength += encoder.prependVarNumber(doubleLength);
  totalLength += encoder.prependVarNumber(ndn::lp::location::Latitude);

  totalLength += encoder.prependVarNumber(totalLength);
  totalLength += encoder.prependVarNumber(ndn::lp::tlv::DLocation);

  return totalLength;
}

NDN_CXX_DEFINE_WIRE_ENCODE_INSTANTIATIONS(DLocation);

// const Block&
// Location::wireEncode() const
// {
//   EncodingEstimator estimator;
//   size_t estimatedSize = wireEncode(estimator);

//   EncodingBuffer buffer(estimatedSize, 0);
//   wireEncode(buffer);

//   m_wire = buffer.block();

//   return m_wire;
//   return nullptr;
// }

void
DLocation::wireDecode(const Block& wire)
{
  std::cout << "DLocation wireDecode()" << std::endl;

  if (wire.type() != ndn::lp::tlv::DLocation) {
    BOOST_THROW_EXCEPTION(Error("Unexpected TLV-TYPE " + to_string(wire.type())));
  }

  wire.parse();

  ndn::Block::element_const_iterator val  = wire.elements_begin();

  if (val != wire.elements_end() && val->type() == ndn::lp::location::Latitude) {
    val->parse();
    ndn::Block::element_const_iterator it = val->elements_begin();
    if (it != val->elements_end() && val->type() == ndn::lp::location::Double) {
      m_latitude = *reinterpret_cast<const double*>(it->value());

      ++val;
    }
    else {
      std::cout << "Missing required Location Double field" << std::endl;
      BOOST_THROW_EXCEPTION(Error("Missing required Double field"));
    }
  }
  else {
    std::cout << "Location Latitude: Missing required Location Latitude field" << std::endl;
    BOOST_THROW_EXCEPTION(Error("Location Latitude : Missing required Location Latitude field"));
  }

  if (val != wire.elements_end() && val->type() == ndn::lp::location::Longitude) {
    val->parse();
    ndn::Block::element_const_iterator it = val->elements_begin();
    if (it != val->elements_end() && val->type() == ndn::lp::location::Double) {
      m_longitude = *reinterpret_cast<const double*>(it->value());
    }
    else {
      std::cout << "Location Longitude: Missing required Location Double field" << std::endl;
      BOOST_THROW_EXCEPTION(Error("Missing required Double field"));
    }
  }
  else {
    std::cout << "Missing required Location Longitude field" << std::endl;
    BOOST_THROW_EXCEPTION(Error("Missing required Location Longitude field"));
  }
}

}
}

