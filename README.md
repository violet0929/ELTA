# ELTA

Exclusive Link Traffic Allocation in IEEE 802.11be Asynchronous Multi Link Operation

### Table of Contents

* [Overview](#overview)
  * [Introduction](#introduction)
  * [Problem Formulation](#problem formulation)
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

![image-20241105115514317](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\image-20241105115514317.png)



![image-20241105115529467](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\image-20241105115529467.png)



![image-20241105115553616](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\image-20241105115553616.png)



![image-20241105115612565](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\image-20241105115612565.png)



### ELTA

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
19/1960r1, Nov. 2019.

* [20] G. Smith, 802.11mc TXOP Limits, document IEEE 802.11-13/0014r0,2013.

* [21] Liu, Wen-Jiunn, Chao-Hua Huang, and Kai-Ten Feng. "Performance analysis of block acknowledgement mechanisms for next generation wireless networks." 2010 IEEE Wireless Communication and Networking Conference. IEEE, 2010.
  
* [22] Multi-link operation with enhanced synchronous channel access in IEEE 802.11 be wireless LANs: Coexistence issue and solutions
  * Sensors, 2021

* [23] Multilink operation in IEEE 802.11 be wireless LANs: Backoff overflow problem and solutions
  * Sensors, 2022

* [24] López-Raventós, Alvaro, and Boris Bellalta. "Multi-link operation in IEEE 802.11 be WLANs." IEEE Wireless Communications 29.4 (2022): 94-100.

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

```
./ns3 run ELTA-simulator
```

