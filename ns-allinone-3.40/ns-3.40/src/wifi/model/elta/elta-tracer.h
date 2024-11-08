//
// Created by test on 11/8/24.
//

#ifndef ELTA_TRACER_H
#define ELTA_TRACER_H

#include "ns3/log.h"
#include "ns3/nstime.h"
#include "ns3/mac48-address.h"
#include "ns3/wifi-ppdu.h"

namespace ns3
{
class EltaTracer;

class EltaTracer
{
  public:
    EltaTracer();

    EltaTracer(int nSTA);

    void SendQosData(TimeWithUnit unit, Mac48Address device, uint8_t linkId, Mac48Address src, Mac48Address dst,
                     uint32_t psduSize,
                     uint16_t seqNo, uint8_t qosTid, bool retry);

    void SendNormalAck(TimeWithUnit unit, Mac48Address address, uint8_t linkId, Mac48Address src,
                       Mac48Address dst, uint32_t mpduSize, bool b);

    void SendBlockAck(TimeWithUnit unit, Mac48Address address, uint8_t linkId, Mac48Address src,
                      Mac48Address dst, uint32_t mpduSize, bool b);

    void SendBlockAckReq(TimeWithUnit unit, Mac48Address address, uint8_t linkId, Mac48Address src,
                         Mac48Address dst, uint32_t mpduSize, bool b);

    void SendOther(TimeWithUnit unit, Mac48Address address, uint8_t linkId, Mac48Address src,
                   Mac48Address dst, uint32_t mpduSize, bool b);

    void ReceiveQosData(TimeWithUnit unit, Mac48Address device, uint8_t linkId, Mac48Address src, Mac48Address dst,
                        uint32_t psduSize,
                        uint16_t seqNo, uint8_t qosTid, bool retry);

    void ReceiveNormalAck(TimeWithUnit unit, Mac48Address address, uint8_t linkId, Mac48Address src,
                          Mac48Address dst, uint32_t mpduSize, bool b);

    void ReceiveBlockAck(TimeWithUnit unit, Mac48Address address, uint8_t linkId, Mac48Address src,
                         Mac48Address dst, uint32_t mpduSize, bool b);

    void ReceiveBlockAckReq(TimeWithUnit unit, Mac48Address address, uint8_t linkId, Mac48Address src,
                            Mac48Address dst, uint32_t mpduSize, bool b);

    void ReceiveOther(TimeWithUnit unit, Mac48Address address, uint8_t linkId, Mac48Address src,
                      Mac48Address dst, uint32_t mpduSize, bool b);

    void ConditionalIOStream(const std::string &subject, const int &linkId, const std::vector<std::string> &elements,
                             const std::string &delimiter);

    void IOStream(const std::string &subject, const int &linkId, const std::vector<std::string> &elements,
                  const std::string &delimiter);

  private:
    static int m_nSTA;
};
} // namespace ns3

#endif