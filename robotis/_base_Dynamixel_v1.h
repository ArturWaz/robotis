//
// Created by geox on 15.07.15.
//

#ifndef _BASE_DYNAMIXEL_V1_H
#define _BASE_DYNAMIXEL_V1_H


#include <cstdint>



class _base_Dynamixel_v1 {
public:

    _base_Dynamixel_v1();

    uint32_t splitPackets(std::uint8_t const *inputBuffer, std::uint32_t inputLength, std::uint8_t **outputPackets, std::uint32_t maxNumberOfPackets, std::uint32_t maxNumberOfBytes);

    static std::uint8_t checksum(std::uint8_t const *packet);

private:

    std::uint8_t packet_[254] = {};
    std::uint8_t *const packetBegin_;
    std::uint8_t *const packetEnd_;

    std::uint8_t *ptrPacketCur_;
    std::uint8_t *ptrPacketBegin_;
    std::uint8_t *ptrPacketEnd_;

};


#endif //DYNAMIXEL__BASE_DYNAMIXEL_V1_H
