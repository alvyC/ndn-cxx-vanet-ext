/**
 * @author: Jeff Thompson
 * See COPYING for copyright and distribution information.
 */

#ifndef NDN_TRANSPORT_HPP
#define	NDN_TRANSPORT_HPP

#include <vector>

namespace ndn {

class NDN;  
class Transport {
public:
  /**
   * 
   * @param ndn Not a shared_ptr because we assume that it will remain valid during the life of this Transport object.
   */
  virtual void connect(NDN &ndn);
  
  virtual void send(const unsigned char *data, unsigned int dataLength);
  
  void send(const std::vector<unsigned char> &data)
  {
    send(&data[0], data.size());
  }
};

}

#endif
