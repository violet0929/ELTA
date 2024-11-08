//
// Created by test on 11/8/24.
//
#include "elta-handler.h"

#include "iostream"

namespace ns3
{

int EltaHandler::m_nSTA;
int EltaHandler::m_nLink;

std::vector<std::vector<AcIndex>> EltaHandler::m_exclusiveACVector;
std::vector<std::vector<int>> EltaHandler::m_stateExclusiveLinkVector;

EltaHandler::EltaHandler()
{
}

EltaHandler::EltaHandler(int nSTA, int nLink)
{
    m_nSTA = nSTA;
    m_nLink = nLink;
    std::vector<int> innerVector1(m_nLink);
    std::fill(innerVector1.begin(), innerVector1.end(), 0);

    for (int i = 0; i < m_nSTA; i++)
    {
        m_stateExclusiveLinkVector.push_back(innerVector1);
    }

    std::vector<AcIndex> innerVector2(m_nLink);
    std::fill(innerVector2.begin(), innerVector2.end(), AC_VO);

    for (int i = 0; i < m_nSTA; i++)
    {
        m_exclusiveACVector.push_back(innerVector2);
    }
}

template <typename T>
std::string
toString(const T& value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

AcIndex
EltaHandler::ImplicitPrioritySeparation(Mac48Address addr, uint8_t linkId, std::vector<double> qVector, std::vector<double> pVector)
{
    std::string originator;
    int idx = 0;

    originator = toString(addr).substr(toString(addr).length() - 2, 2);

    idx = ((int)std::stoi(originator, nullptr, 16) - 1) / 3;

    std::cout << "EDCA Q State: ";
    for (double val : qVector)
    {
        std::cout << val << " ";
        std::cout << "| ";
    }
    std::cout << std::endl;

    std::cout << "EDCA P State: ";
    for (double val : pVector)
    {
        std::cout << val << " ";
        std::cout << "| ";
    }
    std::cout << std::endl;

    if(qVector[1] / qVector[0] > pVector[1] / pVector[0]){
        m_exclusiveACVector[idx][linkId] = AC_VI;
        return m_exclusiveACVector[idx][linkId];
    }
    else{
        m_exclusiveACVector[idx][linkId] = AC_VO;
        return m_exclusiveACVector[idx][linkId];
    }
}

void
EltaHandler::ActivateExclusiveLink(Mac48Address addr, uint8_t linkId, uint8_t tid)
{
    std::string originator;
    int idx = 0;

    originator = toString(addr).substr(toString(addr).length() - 2, 2);

    idx = ((int)std::stoi(originator, nullptr, 16) - 1) / 3;

    /* tid: 3 (AC_BE), 5 (AC_VI), 6 (AC_VO) */

    if (idx <= m_nSTA)
    {
        if ((int)tid == 6)
        {
            std::cout << "STA: " << idx + 1;
            std::cout << ", Link: " << (int)linkId + 1;
            std::cout << ", BA Timeout -> Activate Exclusive Link" << std::endl;
            m_stateExclusiveLinkVector[idx][linkId] = 1;
        }
    }
    PrintStateExclusiveLinkVector();
}

bool
EltaHandler::IsActivateExclusiveLink(Mac48Address addr, uint8_t linkId)
{
    std::string originator;
    int idx = 0;

    originator = toString(addr).substr(toString(addr).length() - 2, 2);

    idx = ((int)std::stoi(originator, nullptr, 16) - 1) / 3;

    return m_stateExclusiveLinkVector[idx][linkId];
}

void
EltaHandler::DeActivateExclusiveLink(Mac48Address addr, uint8_t linkId, AcIndex ac)
{
    std::string originator;
    int idx = 0;

    originator = toString(addr).substr(toString(addr).length() - 2, 2);

    idx = ((int)std::stoi(originator, nullptr, 16) - 1) / 3;

    /* tid : 3 (AC_BE), 5 (AC_VI), 6 (AC_VO) */

    std::cout << "STA: " << idx + 1;
    std::cout << ", Link: " << (int)linkId + 1;
    std::cout << ", StartFrameExchange -> Deactivate Exclusive Link" << std::endl;
    m_stateExclusiveLinkVector[idx][linkId] = 0;
    PrintStateExclusiveLinkVector();
}

void
EltaHandler::PrintStateExclusiveLinkVector()
{
    std::cout << "Exclusive Link State: ";
    for (const auto& innerVec : m_stateExclusiveLinkVector)
    {
        for (int val : innerVec)
        {
            std::cout << val << " ";
        }
        std::cout << "| ";
    }
    std::cout << std::endl;
}

AcIndex
EltaHandler::GetExclusiveAccessCategory(Mac48Address addr, uint8_t linkId)
{
    std::string originator;
    int idx = 0;

    originator = toString(addr).substr(toString(addr).length() - 2, 2);

    idx = ((int)std::stoi(originator, nullptr, 16) - 1) / 3;

    return m_exclusiveACVector[idx][linkId];
}
} // namespace ns3
