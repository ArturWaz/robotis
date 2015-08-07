//
// Created by geox on 15.07.15.
//


#include "asynchronousPacketReader.h"

#include <cstring>
#include <stdexcept>
#include <iostream>



asynchronousPacketReader::asynchronousPacketReader():
        packetBegin_(&(packet_[5])),
        packetEnd_(&(packet_[254])),
        ptrPacketCur_(packetBegin_),
        ptrPacketBegin_(nullptr),
        ptrPacketEnd_(nullptr) {}


uint32_t asynchronousPacketReader::splitPackets(uint8_t const *inputBuffer, uint32_t inputLength, uint8_t **outputPackets, uint32_t maxNumberOfPackets, uint32_t maxNumberOfBytes) {
    if (maxNumberOfPackets < 1 || maxNumberOfBytes < 5) return 0;
    uint32_t numberOfPackets = 0;

    for (uint8_t const *ptrBuff = &(inputBuffer[0]); ptrBuff != &(inputBuffer[inputLength]); ++ptrBuff) {
        *ptrPacketCur_ = *ptrBuff;

        if (ptrPacketEnd_ == nullptr) {
            uint8_t *ptrTmp = ptrPacketCur_-1;
            if (*(--ptrTmp) == 0xFF) {
                if (*(--ptrTmp) == 0xFF) {
                    if (maxNumberOfBytes < (*ptrPacketCur_) + uint32_t(5))
                        throw std::range_error(" [ asynchronousPacketReader::splitPackets(...) ]: Maximum number of bytes is too small.\n");
                    ptrPacketEnd_ = ptrPacketCur_ + (*ptrPacketCur_);
                    ptrPacketBegin_ = ptrTmp;
                }
            }
        }

        if (ptrPacketEnd_ == ptrPacketCur_) {
            uint8_t checksum = 0;
            for (uint8_t *ptr = ptrPacketBegin_+2; ptr != ptrPacketEnd_; ++ptr)
                checksum += *ptr;
            checksum = ~checksum;
            if (checksum == *ptrPacketEnd_) {
                std::memcpy(outputPackets[numberOfPackets],ptrPacketBegin_,sizeof(uint8_t)*(4+(*(ptrPacketBegin_+3))));
                ++numberOfPackets;
                if (maxNumberOfPackets <= numberOfPackets) return numberOfPackets;
            }
            else std::cerr << "\tWARNING: [ asynchronousPacketReader::splitPackets(...) ]: Different checksums.\n";
            ptrPacketEnd_ = nullptr;
            ptrPacketCur_ = packetBegin_;
        }

        ++ptrPacketCur_;
        if (ptrPacketCur_ == packetEnd_) {
            ptrPacketCur_ = packetBegin_;
            std::cerr << "\tWARNING: [ asynchronousPacketReader::splitPackets(...) ]: Many packets lost.\n";
        }
    }

    return numberOfPackets;
}


void asynchronousPacketReader::resetSpliting() {
    ptrPacketEnd_ = nullptr;
    ptrPacketCur_ = packetBegin_;
}




