//
// Created by geox on 15.07.15.
//


#include "_base_Dynamixel_v1.h"

#include <cstring>
#include <stdexcept>
#include <iostream>



_base_Dynamixel_v1::_base_Dynamixel_v1():
        packetBegin_(&(packet_[5])),
        packetEnd_(&(packet_[254])),
        ptrPacketCur_(packetBegin_),
        ptrPacketBegin_(nullptr),
        ptrPacketEnd_(nullptr) {}


uint32_t _base_Dynamixel_v1::splitPackets(std::uint8_t const *inputBuffer, std::uint32_t inputLength, std::uint8_t **outputPackets, std::uint32_t maxNumberOfPackets, std::uint32_t maxNumberOfBytes) {
    if (maxNumberOfPackets < 1 || maxNumberOfBytes < 5) return 0;
    std::uint32_t numberOfPackets = 0;

    for (std::uint8_t const *ptrBuff = &(inputBuffer[0]); ptrBuff != &(inputBuffer[inputLength]); ++ptrBuff) {
        *ptrPacketCur_ = *ptrBuff;

        if (ptrPacketEnd_ == nullptr) {
            std::uint8_t *ptrTmp = ptrPacketCur_-1;
            if (*(--ptrTmp) == 0xFF) {
                if (*(--ptrTmp) == 0xFF) {
                if (maxNumberOfBytes < (*ptrPacketCur_) + std::uint32_t(5))
                    throw std::range_error(" [ _base_Dynamixel_v1::splitPackets(...) ]: Maximum number of bytes is too small.\n");
                ptrPacketEnd_ = ptrPacketCur_ + (*ptrPacketCur_);
                ptrPacketBegin_ = ptrTmp;
                }
            }
        }

        if (ptrPacketEnd_ == ptrPacketCur_) {
            std::uint8_t checksum = 0;
            for (std::uint8_t *ptr = ptrPacketBegin_+2; ptr != ptrPacketEnd_; ++ptr)
                checksum += *ptr;
            checksum = ~checksum;
            if (checksum == *ptrPacketEnd_) {
                std::memcpy(outputPackets[numberOfPackets],ptrPacketBegin_,sizeof(std::uint8_t)*(4+(*(ptrPacketBegin_+3))));
                ++numberOfPackets;
                if (maxNumberOfPackets <= numberOfPackets) return numberOfPackets;
            }
            else std::cerr << "\tWARNING: [ _base_Dynamixel_v1::splitPackets(...) ]: Different checksums.\n";
            ptrPacketEnd_ = nullptr;
            ptrPacketCur_ = packetBegin_;
        }

        ++ptrPacketCur_;
        if (ptrPacketCur_ == packetEnd_) {
            ptrPacketCur_ = packetBegin_;
            std::cerr << "\tWARNING: [ _base_Dynamixel_v1::splitPackets(...) ]: Many packets lost.\n";
        }
    }

    return numberOfPackets;
}


std::uint8_t _base_Dynamixel_v1::checksum(std::uint8_t const *packet) {
    std::uint8_t checksum = 0;
    for (std::uint8_t const *ptr = packet+2; ptr != packet+3+(*(packet+3)); ++ptr) checksum += *ptr;
    return ~checksum;
}

