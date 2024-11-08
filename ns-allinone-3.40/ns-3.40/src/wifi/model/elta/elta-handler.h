//
// Created by test on 11/8/24.
//

#ifndef ELTA_HANDLER_H
#define ELTA_HANDLER_H

#include "ns3/mac48-address.h"
#include "ns3/qos-utils.h"

#include <unordered_map>

namespace ns3
{
class EltaHandler;

class EltaHandler
{
  public:
    EltaHandler();

    EltaHandler(int nSTA, int nLinks);

    void ImplicitPrioritySeparation();

    void ActivateExclusiveLink(Mac48Address addr, uint8_t linkId, uint8_t tid);

    bool IsActivateExclusiveLink(Mac48Address addr, uint8_t linkId);

    void TryDeActivateExclusiveLink(Mac48Address addr, uint8_t linkId, AcIndex ac);

    void PrintStateExclusiveLinkVector();

    AcIndex GetExclusiveAccessCategory();

  private:
    static int m_nSTA;
    static int m_nLink;
    static std::vector<std::vector<int>> m_stateExclusiveLinkVector;
};
} // namespace ns3

#endif