### Overview
* All code to perform the analysis is based on [ns-3.40](https://www.nsnam.org/releases/ns-3-40/).
* Focus on ns-3 MAC low & MAC high & PHY model implementation.
* WifiNetDevice architecture. For 802.11be Multi-Link Devices (MLDs), there as many instances of WifiPhy, FrameExchangeManager and ChannelAccessManager as the number of links.
  * Reference: https://www.nsnam.org/docs/release/3.40/models/singlehtml/index.html#document-wifi
    
  ![image](https://www.nsnam.org/docs/release/3.40/models/singlehtml/_images/WifiArchitecture.png)

### Appendix
* A. AC_BE Retransmission
* B. AC_VI Retransmission
* C. Block Ack communication
* D. MAC layer Buffer (i.e., MPDU Buffer)
* E. Performance (e.g., Throughput, Latency, etc.)
