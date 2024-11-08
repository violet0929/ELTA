# ELTA

Exclusive Link Traffic Allocation in IEEE 802.11be Asynchronous Multi Link Operation

### Table of Contents

* [Overview](#overview)
  * [Introduction](#introduction)
  * [Problem Formulation](#problem-formulation)
  * [ELTA](#elta)
  * [Evaluation](#evluation)
  * [References](#references)
  * [Supplementary](#supplementary)
* [Running](#running)
  * [Packages](#package)

## Overview

### Introduction

* In theory, **the convergence of asynchronous multi-link operation and EDCA technology** not only provides enhanced QoS through efficient utilization of multiple links, but also increases transmission efficiency such as high throughput and low latency based on increased channel bandwidth capacity.
* Nevertheless, due to the inherent characteristics of wireless communications such as interference between multiple transmitters and receivers and signal attenuation due to obstacles, **retransmission may occur, which naturally increases the worst-case latency** (i.e., This situation is particularly detrimental to the performance of high-priority traffic).
* In this project, we propose an exclusive link-based traffic allocation mechanism using a probabilistic implicit priority separation algorithm, named **ELTA**, applicable in a practical multi-link operation environment **to solve the worst-case latency problem of high priority traffic** (i.e., AC_VO, AC_VI traffic).
* Here is a brief summary of this project.
  * A scenario-based analysis is performed **to find out why high latency for traffic corresponding to the high priority AC in an asynchronous multi-link operation-based EDCA environment**. In most cases, the measured high delays is obviously caused by high transmission delays due to the loss of transmitted frames. Scenario analysis is performed including the frame exchange process over time and the state of the transmitter's MPDU buffer.
  * Next, based on **some modifications to the ns-3 wifi module**, a **probability-based implicit priority separation algorithm** to resolve the ambiguity between the theoretical and the practical high priority AC, and an **exclusive link-based traffic allocation mechanism** to ensure primary transmission of high priority traffic described in detail based on pseudo code algorithms and flow chart.
  * Finally, we evaluate the proposed traffic allocation mechanism **in terms of 95 and 99 percentile tail latency and worst case latency** derived from the coexistence of AC traffic based on various network environments classified as sufficient and insufficient network environments.

### Problem Formulation
* Frame Exchange process #1
<p align="center">  
  <img src="https://github.com/user-attachments/assets/bca15c91-e234-4867-baca-ceaa5ae37809" width="100%">
</p>

* MPDU Buffer Status #1
<p align="center">  
  <img src="https://github.com/user-attachments/assets/f465a5f7-5f94-45d4-af94-5c98e23d53ad">
</p>

* MPDU Buffer Status #2
<p align="center">  
  <img src="https://github.com/user-attachments/assets/10b3f977-fff5-47c4-92ca-ea7bbe9fa1ec">
</p>

* Frame Exchange process #2
<p align="center">  
  <img src="https://github.com/user-attachments/assets/4ff2a9d9-dca6-4c65-a3cb-c5377392f4f2" width="100%">
</p>

### ELTA
* Algorithm 1: Probabilistic-based for Implicit Priority Separation
```c
Function ImplicitPrioritySeparation():
    /* Initialize */
    std::vector<std::string> acVector = {"AC_VO", "AC_VI", "AC_BE", "AC_VK"};
    std::vector<std::queue> qVector(4);
    std::vector<std::double> pVector(4);

    for i from 0 to length(qVector) - 1 do
        /* Push the WifiMacQueue of each AC to qVector */        
        qVector[i].push(m_mac->GetTxopQueue(acList[i]));
         /* Allocate EDCA parameter value if WifiMacQueue is not empty */    
        if qVector[i]->GetNPackets() > 0 then
            aifsn = acVector[i]->GetAifsn();      
            cwMin = acVector[i]->GetCwMin();      
            cwMax = acVector[i]->GetCwMax();      
            avgWaitingTime = aifsn + (cwMin + cwMax) / 2;      
            probability = 1 / avgWaitingTime;    
        else then
            probability = 0;    
        end if
        /* Push the probability to pVector */       
        pVector[i].push(probability);    
        totalProbability += probability; 
    end for
    /* Calculate Occupancy and Probability for AC_VO and AC_VI */ 
    q_VO = queueVector[0].m_nBytes / queueVector[0].m_maxSize;  
    q_VI = queueVector[1].m_nBytes / queueVector[1].m_maxSize;
    p_VO = pVector[0] / totalProbability;
    p_VI = pVector[1] / totalProbability;
    /* Allocate exclusive_AC */
    if (q_VI/q_VO) >= (p_VI/p_VO) then
        exclusive_AC = AC_VI;  
    else then
        exclusive_AC = AC_VO;
    end if
    return exclusive_AC;
```

* Algorithm 2: Activation and Deactivation process of exclusive link
```c
Function ExclusiveLinkHandler(eventType):
    /* Initialize */
    std::string exclusive_AC;
    std::vector<std::int> stateExclusiveLinkVector(nLinks); 

    if eventType == AckTimeout or eventType == BlockAckTimeout then
        /* Timeout event is triggered, invoke ImplicitPrioritySeparation */
        exclusive_AC = ImplicitPrioritySeparation();
        if psdu->GetAccessCategory() == exclusive_AC:
            /* Activate exclusive link for the link to which the psdu that has timeout occurred is transmitted */
            stateExclusiveLinkVector[m_linkId] =  1;
        end if
    else if eventType == StartFrameExchange then
        if stateExclusiveLinkVector[m_linkId] == 1 and edca->AccessCategory() == exclusive_AC
           and !GetBar(edca->AccessCategory()) and !GetRetryMpdu(edca->AccessCategory()) then
            /* Deactivate exclusive link for the link that satisfies the following conditions 
                Condition 1: Current link state is an active exclusive link
                Condition 2: AC of the obtained TXOP is the same as exclusive_AC
                Condition 3: There is no BlockAckRequest frame in the AC Queue of the obtained TXOP
                Condition 4: There is no retransmission frame in the AC Queue of the obtained TXOP  */      
            stateExclusiveLinkVector[m_linkId] =  0;
         end if
     end if  
  return;
```
### Evaluation

### References

* [1] IEEE Standard for Information technology--Local and metropolitan area networks--Specific requirements--Part 11: Wireless LAN Medium Access Control (MAC) and Physical Layer (PHY) Specifications - Amendment 8: Medium Access Control (MAC) Quality of Service Enhancement

* [2] IEEE Standard for Information Technology--Telecommunications and Information Exchange between Systems Local and Metropolitan Area Networks--Specific Requirements Part 11: Wireless LAN Medium Access Control (MAC) and Physical Layer (PHY) Specifications Amendment 1: Enhancements for High-Efficiency WLAN
  
* [3] IEEE Draft Standard for Information technology--Telecommunications and information exchange between systems Local and metropolitan area networks--Specific requirements - Part 11: Wireless LAN Medium Access Control (MAC) and Physical Layer (PHY) Specifications Amendment: Enhancements for Extremely High Throughput (EHT)

* [4] IEEE 802.11 ax: Highly efficient WLANs for intelligent information infrastructure
  * IEEE Communications Magazine, 2017

* [5] A review of OFDMA and Single-Carrier FDMA
  * European Wireless Conference, 2010

* [6] Spatial Reuse in IEEE 802.11ax WLANs
  * Computer Communications, 2021

* [7] IEEE 802.11 be Wi-Fi 7: New challenges and opportunities
  * IEEE Communications Surveys & Tutorials, 2020
  
* [8] Overview and performance evaluation of Wi-Fi 7
  * IEEE Communications Standards Magazine, 2022

* [9] Current status and directions of IEEE 802.11 be, the future Wi-Fi 7
  * IEEE Access 8, 2020

* [10] Multi-Link Operation in IEEE 802.11be Extremely High Throughput: A Survey
  * IEEE Access, 2024

* [11] Performance and coexistence evaluation of IEEE 802.11 be multi-link operation
  * IEEE Wireless Communications and Networking Conference, 2023

* [12] A Load Adaptive IEEE 802.11e EDCA Backoff Scheme with Enhanced Service Differentiation
  * IEEE 12th International Conference on Communication Technology, 2010

* [13] Analytical Study of the IEEE 802.11p EDCA Mechanism
  * IEEE Intelligent Vehicles Symposium, 2013

* [14] Adaptive Backoff Algorithm for EDCA in the IEEE 802.11p protocol
  * International Wireless Communications and Mobile Computing Conference, 2016
  
* [15] An experimental study of latency for IEEE 802.11 be multi-link operation
  * IEEE International Conference on Communications, 2022

* [16] Latency Impact for Massive Real-Time Applications on Multi Link Operation
  * IEEE Region 10 Symposium, 2021

* [17] Time-sensitive networking in IEEE 802.11 be: On the way to low-latency WiFi 7
  * Sensors, 2021

* [18] S. Adhikari, S. Verma, M. Fischer, and V. Erceg, Proposals on Latency
Reduction, document IEEE 802.11-20/0005r0, Jan. 2020.

* [19] M. Abouelseoud, K. Sakoda, L. Xin, A. Kishida, K. Nagata, and S. Kim,
Reducing Channel Access Delay for RTA Traffic, document IEEE 802.11-
19/1960r1, Nov. 2019

* [20] G. Smith, 802.11mc TXOP Limits, document IEEE 802.11-13/0014r0,2013.

* [21] Performance analysis of block acknowledgement mechanisms for next generation wireless networks.
  * 2010 IEEE Wireless Communication and Networking Conference, 2010.
  
* [22] Multi-link operation with enhanced synchronous channel access in IEEE 802.11 be wireless LANs: Coexistence issue and solutions
  * Sensors, 2021

* [23] Multilink operation in IEEE 802.11 be wireless LANs: Backoff overflow problem and solutions
  * Sensors, 2022

* [24] Multi-link operation in IEEE 802.11 be WLANs
  * IEEE Wireless Communications, 2022

* [25] IEEE 802.11 be multi-link operation: When the best could be to use only a single interface
  * MedComNet, 2021
  
* [26] Dynamic traffic allocation in IEEE 802.11 be multi-link WLANs
  * IEEE Wireless Communications Letters, 2022

* [27] RL meets Multi-Link Operation in IEEE 802.11 be: Multi-Headed Recurrent Soft-Actor Critic-based Traffic Allocation
  * arXiv preprint arXiv:2303.08959., 2023

* [28] Is Multi-Link Operation of 802.11be TCP Friendly? Analysis and Solution
  * IFIP Networking Conference, 2024
  
* [29] "IEEE Standard for Information technology—Telecommunications and information exchange between systems Local and metropolitan area networks—Specific requirements - Part 11: Wireless LAN Medium Access Control (MAC) and Physical Layer (PHY) Specifications," in IEEE Std 802.11-2016 (Revision of IEEE Std 802.11-2012) , vol., no., pp.1-3534, 14 Dec. 2016, doi: 10.1109/IEEESTD.2016.7786995.

### Supplementary

* ns-3 Code Analysis
  * A. AC_BE Retransmission
  * B. AC_VI Retransmission
  * C. Block Ack communication
  * D. MAC layer Buffer (i.e., MPDU Buffer)
  * E. Performance (e.g., Throughput, Latency, etc.)

## Running

### Packages

* Ubuntu: 22.04
* ns-3: 3.40
* python: 3.12
* CMake: 3.29.6
* GCC: 11.4.0



### Run
#### 권장 설정 처리량
* VI가 VO 보다 암묵적 우선순위가 높게하는 처리량 값이 있는데,, 변수가 너무 많아서 일단 해보는데까지 해보기
  
#### wifi model 일부 수정 부분
```
ns3::WifiMac
ns3::WifiMac::ConfigureDcf
ns3::HtFrameExchangeManager::StartFrameExchange
ns3::HtFrameExchangeManager::BlockAckTimeout
ns3::HtFrameExchangeManager::ForwardPsduDown
ns3::FrameExchangeManager::Receive
```

#### 추가 부분
```
./ns-3.40/scratch/ELTA-simulator.cc
```

```
./ns-3.40/src/wifi/model/elta/elta-handler.h'
./ns-3.40/src/wifi/model/elta/elta-handler.cc'
```

```
./ns-3.40/src/wifi/model/elta/elta-tracer.h'
./ns-3.40/src/wifi/model/elta/elta-tracer.cc'
```

#### 시뮬레이터 실행
```
./ns3 run ELTA-simulator
```

