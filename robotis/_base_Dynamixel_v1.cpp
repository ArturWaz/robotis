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


uint32_t _base_Dynamixel_v1::splitPackets(uint8_t const *inputBuffer, uint32_t inputLength, uint8_t **outputPackets, uint32_t maxNumberOfPackets, uint32_t maxNumberOfBytes) {
    if (maxNumberOfPackets < 1 || maxNumberOfBytes < 5) return 0;
    uint32_t numberOfPackets = 0;

    for (uint8_t const *ptrBuff = &(inputBuffer[0]); ptrBuff != &(inputBuffer[inputLength]); ++ptrBuff) {
        *ptrPacketCur_ = *ptrBuff;

        if (ptrPacketEnd_ == nullptr) {
            uint8_t *ptrTmp = ptrPacketCur_-1;
            if (*(--ptrTmp) == 0xFF) {
                if (*(--ptrTmp) == 0xFF) {
                    if (maxNumberOfBytes < (*ptrPacketCur_) + uint32_t(5))
                        throw std::range_error(" [ _base_Dynamixel_v1::splitPackets(...) ]: Maximum number of bytes is too small.\n");
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


void _base_Dynamixel_v1::resetSpliting() {
    ptrPacketEnd_ = nullptr;
    ptrPacketCur_ = packetBegin_;
}


void _base_Dynamixel_v1::pingEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID) {
    if (maxPacketLength < 6) throw std::range_error(" [ MX_28::sendPresentPosition(uint8_t *, uint32_t, uint8_t ID) ]: Packet length is too short.\n");
    packet[0] = 0xFF;
    packet[1] = 0xFF;
    packet[2] = ID;
    packet[3] = 0x02;
    packet[4] = 0x01;
    packet[5] = ~(ID+uint8_t(0x03));
}


uint8_t _base_Dynamixel_v1::statusResponse(uint8_t const *packet, uint8_t &ID) {
    ID = packet[2];
    return packet[4];
}


uint8_t _base_Dynamixel_v1::calculateChecksum(uint8_t const *packet) {
    uint8_t checksum = 0;
    for (uint8_t const *ptr = packet+2; ptr != packet+3+(*(packet+3)); ++ptr) checksum += *ptr;
    return ~checksum;
}


bool _base_Dynamixel_v1::validateChecksum(uint8_t const *packet, uint32_t maxPacketLength) {
    if (maxPacketLength < *(packet+3)) return false;
    uint8_t checksum = 0;
    for (uint8_t const *ptr = packet+2; ptr != packet+3+(*(packet+3)); ++ptr) checksum += *ptr;
    return *(packet+3+(*(packet+3))) == uint8_t(~checksum);
}


bool _base_Dynamixel_v1::validatePacket(uint8_t const *packet, uint32_t maxPacketLength) {
    if (maxPacketLength < *(packet+3)) return false;
    if (*packet != 0xFF && *(packet+1) != 0xFF) return false;
    uint8_t checksum = 0;
    for (uint8_t const *ptr = packet+2; ptr != packet+3+(*(packet+3)); ++ptr) checksum += *ptr;
    return *(packet+3+(*(packet+3))) == uint8_t(~checksum);
}


std::string _base_Dynamixel_v1::errorsToString(uint8_t error) {
    std::string errorS("Error status: ");
    if (!error) return errorS + std::string("No errors.\n");
    if (error & (1<<int(Error::ANGLE_LIMIT_ERROR))) errorS += std::string("\n    * Goal Position is written out of the range from CW Angle Limit to CCW Angle Limit.\n");
    if (error & (1<<int(Error::CHECKSUM_ERROR))) errorS += std::string("    * The Checksum of the transmitted Instruction Packet is incorrect.\n");
    if (error & (1<<int(Error::INPUT_VOLTAGE_ERROR))) errorS += std::string("    * Applied voltage is out of range of operating voltage.\n");
    if (error & (1<<int(Error::INSTRUCTION_ERROR))) errorS += std::string("    * Sent undefined instruction.\n");
    if (error & (1<<int(Error::OVERHEATING_ERROR))) errorS += std::string("    * Internal temperature of Dynamixel is out of the range.\n");
    if (error & (1<<int(Error::OVERLOAD_ERROR))) errorS += std::string("    * The current load cannot be controlled by the set Torque.\n");
    if (error & (1<<int(Error::RANGE_ERROR))) errorS += std::string("    * A command is out of the range for use.\n");
    return errorS;
}

