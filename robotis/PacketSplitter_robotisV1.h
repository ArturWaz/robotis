//
// Created by geox on 15.07.15.
//

#ifndef _BASE_DYNAMIXEL_V1_H
#define _BASE_DYNAMIXEL_V1_H


#include <stdint.h>

#include "_base_communicationV1.h"



class PacketSplitter_robotisV1 {
public:

    PacketSplitter_robotisV1() noexcept;

    uint32_t splitPackets(uint8_t const *inputBuffer, uint32_t inputLength, std::array<uint8_t,ROBOTIS_BUFFER_LENGTH> *outputPackets, uint32_t maxNumberOfPackets) noexcept;
    void resetSpliting() noexcept; // could be useful in timeouts

private:

    uint8_t packet_[254] = {};
    uint8_t *const packetBegin_;
    uint8_t *const packetEnd_;

    uint8_t *ptrPacketCur_;
    uint8_t *ptrPacketBegin_;
    uint8_t *ptrPacketEnd_;

};


#endif //DYNAMIXEL__BASE_DYNAMIXEL_V1_H

