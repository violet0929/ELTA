//
// Created by test on 11/8/24.
//

#ifndef ELTA_HANDLER_H
#define ELTA_HANDLER_H

#include "ns3/mac48-address.h"
#include "ns3/qos-utils.h"
#include "ns3/wifi-mac.h"

#include <unordered_map>

namespace ns3
{
class EltaHandler;

class EltaHandler
{
  public:
    EltaHandler();

    EltaHandler(int nSTA, int nLinks);

    AcIndex ImplicitPrioritySeparation(Mac48Address addr, uint8_t linkId, std::vector<double> qVector, std::vector<double> pVector);

    void ActivateExclusiveLink(Mac48Address addr, uint8_t linkId, uint8_t tid);

    bool IsActivateExclusiveLink(Mac48Address addr, uint8_t linkId);

    void DeActivateExclusiveLink(Mac48Address addr, uint8_t linkId, AcIndex ac);

    void PrintStateExclusiveLinkVector();

    AcIndex GetExclusiveAccessCategory(Mac48Address addr, uint8_t linkId);

    Ptr<WifiMac> m_mac;

  private:
    static int m_nSTA;
    static int m_nLink;
    static std::vector<std::vector<AcIndex>> m_exclusiveACVector;
    static std::vector<std::vector<int>> m_stateExclusiveLinkVector;
};
} // namespace ns3

#endif