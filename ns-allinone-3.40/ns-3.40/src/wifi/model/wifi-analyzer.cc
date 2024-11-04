//
// Created by violet
//

#include "wifi-analyzer.h"
#include <algorithm>

namespace ns3 {
    NS_LOG_COMPONENT_DEFINE("WifiAnalyzer");

    int WifiAnalyzer::nSTA = 1;

    template<typename T>
    std::string toString(const T &value) {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }

    void
    WifiAnalyzer::SendQosData(TimeWithUnit unit, Mac48Address device, uint8_t linkId, Mac48Address src,
                              Mac48Address dst,
                              uint32_t mpduSize,
                              uint16_t seqNo, uint8_t qosTid, bool retry) {
        std::string subject;
        std::string description;

        std::size_t length = toString(device).length();
        std::string addr = toString(device).substr(length - 2, 2);

        if (((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1 == nSTA + 1) {
            subject = "AP";
            if (dst.IsBroadcast()) {
                description = "AP -> Broadcast, QosDATA";
            } else {
                std::string dst_addr = toString(dst).substr(length - 2, 2);
                description = subject + " -> STA" + toString(((int) std::stoi(dst_addr, nullptr, 16) - 1) / 3 + 1) +
                              ", QosDATA";
            }
        } else {
            subject = "STA" + toString(((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1);
            description = subject + " -> AP, QosDATA";
        }

        if (description.empty()) {
            NS_LOG_UNCOND("Description is empty");
        }

        std::vector<std::string> elements;
        std::string delimiter = ", ";

        elements.push_back(toString(unit));
        elements.push_back(toString(description));
        elements.push_back(toString((int) linkId));
        elements.push_back(toString(mpduSize));
        elements.push_back(toString(retry));
        elements.push_back(toString(seqNo));
        elements.push_back(toString((int) qosTid));

        IOStream(subject, (int) linkId, elements, delimiter);

        if (mpduSize > 1400 and (int) qosTid != 0) {
            ConditionalIOStream(subject, (int) linkId, elements, delimiter);
        }
    }

    void WifiAnalyzer::SendNormalAck(TimeWithUnit unit, Mac48Address device, uint8_t linkId, Mac48Address src,
                                     Mac48Address dst, uint32_t mpduSize, bool retry) {
        std::string subject;
        std::string description;

        std::size_t length = toString(device).length();
        std::string addr = toString(device).substr(length - 2, 2);

        if (((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1 == nSTA + 1) {
            subject = "AP";
            if (dst.IsBroadcast()) {
                description = "AP -> Broadcast, NormalACK";
            } else {
                std::string dst_addr = toString(dst).substr(length - 2, 2);
                description = subject + " -> STA" + toString(((int) std::stoi(dst_addr, nullptr, 16) - 1) / 3 + 1) +
                              ", NormalACK";
            }
        } else {
            subject = "STA" + toString(((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1);
            description = subject + " -> AP, NormalACK";
        }

        if (description.empty()) {
            NS_LOG_UNCOND("Description is empty");
        }

        std::vector<std::string> elements;
        std::string delimiter = ", ";

        elements.push_back(toString(unit));
        elements.push_back(toString(description));
        elements.push_back(toString((int) linkId));
        elements.push_back(toString(mpduSize));
        elements.push_back(toString(retry));

        IOStream(subject, (int) linkId, elements, delimiter);

    }

    void WifiAnalyzer::SendBlockAck(TimeWithUnit unit, Mac48Address device, uint8_t linkId, Mac48Address src,
                                    Mac48Address dst, uint32_t mpduSize, bool retry) {
        std::string subject;
        std::string description;

        std::size_t length = toString(device).length();
        std::string addr = toString(device).substr(length - 2, 2);

        if (((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1 == nSTA + 1) {
            subject = "AP";
            if (dst.IsBroadcast()) {
                description = "AP -> Broadcast, BlockACK";
            } else {
                std::string dst_addr = toString(dst).substr(length - 2, 2);
                description = subject + " -> STA" + toString(((int) std::stoi(dst_addr, nullptr, 16) - 1) / 3 + 1) +
                              ", BlockACK";
            }
        } else {
            subject = "STA" + toString(((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1);
            description = subject + " -> AP, BlockACK";
        }


        if (description.empty()) {
            NS_LOG_UNCOND("Description is empty");
        }

        std::vector<std::string> elements;
        std::string delimiter = ", ";

        elements.push_back(toString(unit));
        elements.push_back(toString(description));
        elements.push_back(toString((int) linkId));
        elements.push_back(toString(mpduSize));
        elements.push_back(toString(retry));

        IOStream(subject, (int) linkId, elements, delimiter);

    }

    void WifiAnalyzer::SendBlockAckReq(TimeWithUnit unit, Mac48Address device, uint8_t linkId, Mac48Address src,
                                       Mac48Address dst, uint32_t mpduSize, bool retry) {
        std::string subject;
        std::string description;

        std::size_t length = toString(device).length();
        std::string addr = toString(device).substr(length - 2, 2);

        if (((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1 == nSTA + 1) {
            subject = "AP";
            if (dst.IsBroadcast()) {
                description = "AP -> Broadcast, BlockACKReq";
            } else {
                std::string dst_addr = toString(dst).substr(length - 2, 2);
                description = subject + " -> STA" + toString(((int) std::stoi(dst_addr, nullptr, 16) - 1) / 3 + 1) +
                              ", BlockACKReq";
            }
        } else {
            subject = "STA" + toString(((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1);
            description = subject + " -> AP, BlockACKReq";
        }

        if (description.empty()) {
            NS_LOG_UNCOND("Description is empty");
        }

        std::vector<std::string> elements;
        std::string delimiter = ", ";

        elements.push_back(toString(unit));
        elements.push_back(toString(description));
        elements.push_back(toString((int) linkId));
        elements.push_back(toString(mpduSize));
        elements.push_back(toString(retry));

        IOStream(subject, (int) linkId, elements, delimiter);
    }

    void WifiAnalyzer::SendOther(TimeWithUnit unit, Mac48Address device, uint8_t linkId, Mac48Address src,
                                 Mac48Address dst, uint32_t mpduSize, bool retry) {
        std::string subject;
        std::string description;

        std::size_t length = toString(device).length();
        std::string addr = toString(device).substr(length - 2, 2);

        if (((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1 == nSTA + 1) {
            subject = "AP";
            if (dst.IsBroadcast()) {
                description = "AP -> Broadcast, Other";
            } else {
                std::string dst_addr = toString(dst).substr(length - 2, 2);
                description = subject + " -> STA" + toString(((int) std::stoi(dst_addr, nullptr, 16) - 1) / 3 + 1) +
                              ", Other";
            }
        } else {
            subject = "STA" + toString(((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1);
            description = subject + " -> AP, Other";
        }

        if (description.empty()) {
            NS_LOG_UNCOND("Description is empty");
        }

        std::vector<std::string> elements;
        std::string delimiter = ", ";

        elements.push_back(toString(unit));
        elements.push_back(toString(description));
        elements.push_back(toString((int) linkId));
        elements.push_back(toString(mpduSize));
        elements.push_back(toString(retry));

        IOStream(subject, (int) linkId, elements, delimiter);
    }

    void
    WifiAnalyzer::ReceiveQosData(TimeWithUnit unit, Mac48Address device, uint8_t linkId, Mac48Address src,
                                 Mac48Address dst,
                                 uint32_t mpduSize,
                                 uint16_t seqNo, uint8_t qosTid, bool retry) {
        std::string subject;
        std::string description;

        std::size_t length = toString(device).length();
        std::string addr = toString(device).substr(length - 2, 2);

        if (((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1 == nSTA + 1) {
            subject = "AP";
            std::string src_addr = toString(src).substr(length - 2, 2);
            description =
                    "STA" + toString(((int) std::stoi(src_addr, nullptr, 16) - 1) / 3 + 1) + " <- " + subject +
                    ", QosDATA";
        } else {
            subject = "STA" + toString(((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1);
            description = "AP <- " + subject + ", QosDATA";
        }

        if (description.empty()) {
            NS_LOG_UNCOND("Description is empty");
        }

        std::vector<std::string> elements;
        std::string delimiter = ", ";

        elements.push_back(toString(unit));
        elements.push_back(toString(description));
        elements.push_back(toString((int) linkId));
        elements.push_back(toString(mpduSize));
        elements.push_back(toString(retry));
        elements.push_back(toString(seqNo));
        elements.push_back(toString((int) qosTid));

        IOStream(subject, (int) linkId, elements, delimiter);

        if (mpduSize > 1400 and (int) qosTid != 0) {
            ConditionalIOStream(subject, (int) linkId, elements, delimiter);
        }
    }

    void WifiAnalyzer::ReceiveNormalAck(TimeWithUnit unit, Mac48Address device, uint8_t linkId, Mac48Address src,
                                        Mac48Address dst, uint32_t mpduSize, bool retry) {
        std::string subject;
        std::string description;

        std::size_t length = toString(device).length();
        std::string addr = toString(device).substr(length - 2, 2);

        if (((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1 == nSTA + 1) {
            subject = "AP";
            std::string src_addr = toString(src).substr(length - 2, 2);
            description =
                    "STA" + toString(((int) std::stoi(src_addr, nullptr, 16) - 1) / 3 + 1) + " <- " + subject +
                    ", NormalACK";
        } else {
            subject = "STA" + toString(((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1);
            description = "AP <- " + subject + ", NormalACK";
        }

        if (description.empty()) {
            NS_LOG_UNCOND("Description is empty");
        }

        std::vector<std::string> elements;
        std::string delimiter = ", ";

        elements.push_back(toString(unit));
        elements.push_back(toString(description));
        elements.push_back(toString((int) linkId));
        elements.push_back(toString(mpduSize));
        elements.push_back(toString(retry));

        IOStream(subject, (int) linkId, elements, delimiter);

    }

    void WifiAnalyzer::ReceiveBlockAck(TimeWithUnit unit, Mac48Address device, uint8_t linkId, Mac48Address src,
                                       Mac48Address dst, uint32_t mpduSize, bool retry) {
        std::string subject;
        std::string description;

        std::size_t length = toString(device).length();
        std::string addr = toString(device).substr(length - 2, 2);

        if (((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1 == nSTA + 1) {
            subject = "AP";
            std::string src_addr = toString(src).substr(length - 2, 2);
            description =
                    "STA" + toString(((int) std::stoi(src_addr, nullptr, 16) - 1) / 3 + 1) + " <- " + subject +
                    ", BlockACK";
        } else {
            subject = "STA" + toString(((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1);
            description = "AP <- " + subject + ", BlockACK";
        }

        if (description.empty()) {
            NS_LOG_UNCOND("Description is empty");
        }

        std::vector<std::string> elements;
        std::string delimiter = ", ";

        elements.push_back(toString(unit));
        elements.push_back(toString(description));
        elements.push_back(toString((int) linkId));
        elements.push_back(toString(mpduSize));
        elements.push_back(toString(retry));

        IOStream(subject, (int) linkId, elements, delimiter);

    }

    void WifiAnalyzer::ReceiveBlockAckReq(TimeWithUnit unit, Mac48Address device, uint8_t linkId, Mac48Address src,
                                          Mac48Address dst, uint32_t mpduSize, bool retry) {
        std::string subject;
        std::string description;

        std::size_t length = toString(device).length();
        std::string addr = toString(device).substr(length - 2, 2);

        if (((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1 == nSTA + 1) {
            subject = "AP";
            std::string src_addr = toString(src).substr(length - 2, 2);
            description =
                    "STA" + toString(((int) std::stoi(src_addr, nullptr, 16) - 1) / 3 + 1) + " <- " + subject +
                    ", BlockACkReq";
        } else {
            subject = "STA" + toString(((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1);
            description = "AP <- " + subject + ", BlockACKReq";
        }

        if (description.empty()) {
            NS_LOG_UNCOND("Description is empty");
        }

        std::vector<std::string> elements;
        std::string delimiter = ", ";

        elements.push_back(toString(unit));
        elements.push_back(toString(description));
        elements.push_back(toString((int) linkId));
        elements.push_back(toString(mpduSize));
        elements.push_back(toString(retry));

        IOStream(subject, (int) linkId, elements, delimiter);
    }

    void WifiAnalyzer::ReceiveOther(TimeWithUnit unit, Mac48Address device, uint8_t linkId, Mac48Address src,
                                    Mac48Address dst, uint32_t mpduSize, bool retry) {
        std::string subject;
        std::string description;

        std::size_t length = toString(device).length();
        std::string addr = toString(device).substr(length - 2, 2);

        if (((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1 == nSTA + 1) {
            subject = "AP";
            std::string src_addr = toString(src).substr(length - 2, 2);
            description =
                    "STA" + toString(((int) std::stoi(src_addr, nullptr, 16) - 1) / 3 + 1) + " <- " + subject +
                    ", Other";
        } else {
            subject = "STA" + toString(((int) std::stoi(addr, nullptr, 16) - 1) / 3 + 1);
            description = "AP <- " + subject + ", Other";
        }

        if (description.empty()) {
            NS_LOG_UNCOND("Description is empty");
        }

        std::vector<std::string> elements;
        std::string delimiter = ", ";

        elements.push_back(toString(unit));
        elements.push_back(toString(description));
        elements.push_back(toString((int) linkId));
        elements.push_back(toString(mpduSize));
        elements.push_back(toString(retry));

        IOStream(subject, (int) linkId, elements, delimiter);
    }

    void WifiAnalyzer::ConditionalIOStream(const std::string &subject, const int &linkId,
                                           const std::vector<std::string> &elements,
                                           const std::string &delimiter) {
        std::ostringstream file;
        std::string filePath = "/home/test/ns-allinone-3.40/ns-3.40/scratch/wifi_analyzer_";

        file << filePath << subject << ".txt";

        std::ostringstream data;
        for (size_t i = 0; i < elements.size(); ++i) {
            data << elements[i];
            if (i != elements.size() - 1) {
                data << delimiter;
            }
        }

        std::ofstream outFile(file.str(), std::ios::app);

        if (outFile.is_open()) {
            outFile << data.str() << std::endl;
            outFile.close();
        } else {
            std::cerr << "Failed to open file" << std::endl;
        }
    }

    void WifiAnalyzer::IOStream(const std::string &subject, const int &linkId, const std::vector<std::string> &elements,
                                const std::string &delimiter) {

        std::string file = "/home/test/ns-allinone-3.40/ns-3.40/scratch/wifi_analyzer.txt";

        std::ostringstream data;
        for (size_t i = 0; i < elements.size(); ++i) {
            data << elements[i];
            if (i != elements.size() - 1) {
                data << delimiter;
            }
        }

        std::ofstream outFile(file, std::ios::app);

        if (outFile.is_open()) {
            outFile << data.str() << std::endl;
            outFile.close();
        } else {
            std::cerr << "Failed to open file" << std::endl;
        }
    }

}
