//
// Created by geox on 15.07.15.
//


#include "packetSplitter_robotisV1.h"

#include <cstring>
#include <stdexcept>
#include <iostream>



packetSplitter_robotisV1::packetSplitter_robotisV1() noexcept :
        packetBegin_(&(packet_[5])),
        packetEnd_(&(packet_[254])),
        ptrPacketCur_(packetBegin_),
        ptrPacketBegin_(nullptr),
        ptrPacketEnd_(nullptr) {}


uint32_t packetSplitter_robotisV1::splitPackets(uint8_t const *inputBuffer, uint32_t inputLength, std::array<uint8_t,ROBOTIS_BUFFER_LENGTH> *outputPackets, uint32_t maxNumberOfPackets) noexcept {
    if (maxNumberOfPackets < 1) return 0;
    uint32_t numberOfPackets = 0;

    for (uint8_t const *ptrBuff = &(inputBuffer[0]); ptrBuff != &(inputBuffer[inputLength]); ++ptrBuff) {
        *ptrPacketCur_ = *ptrBuff;

        if (ptrPacketEnd_ == nullptr) {
            uint8_t *ptrTmp = ptrPacketCur_-1;
            if (*(--ptrTmp) == 0xFF) {
                if (*(--ptrTmp) == 0xFF) {
                    ptrPacketBegin_ = ptrTmp;
                    ptrPacketEnd_ = ptrPacketCur_ + (*ptrPacketCur_);
                }
            }
        }

        if (ptrPacketEnd_ == ptrPacketCur_) {
            uint8_t checksum = 0;
            for (uint8_t *ptr = ptrPacketBegin_+2; ptr != ptrPacketEnd_; ++ptr)
                checksum += *ptr;
            checksum = ~checksum;
            if (checksum == *ptrPacketEnd_) {
                std::memcpy(outputPackets[numberOfPackets].data(),ptrPacketBegin_,sizeof(uint8_t)*(ptrPacketEnd_-ptrPacketBegin_+1));
                ++numberOfPackets;
                if (maxNumberOfPackets <= numberOfPackets) return numberOfPackets;
            }
            else std::cerr << "\tWARNING: [ packetSplitter_robotisV1::splitPackets(...) ]: Different checksums.\n";
            ptrPacketEnd_ = nullptr;
            ptrPacketCur_ = packetBegin_;
        }

        ++ptrPacketCur_;
        if (ptrPacketCur_ == packetEnd_) {
            ptrPacketCur_ = packetBegin_;
            std::cerr << "\tWARNING: [ packetSplitter_robotisV1::splitPackets(...) ]: Many packets lost.\n";
        }
    }

    return numberOfPackets;
}


void packetSplitter_robotisV1::resetSpliting() noexcept {
    ptrPacketEnd_ = nullptr;
    ptrPacketCur_ = packetBegin_;
}




