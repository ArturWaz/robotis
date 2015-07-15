//
// Created by geox on 15.07.15.
//

#ifndef _BASE_DYNAMIXEL_V1_H
#define _BASE_DYNAMIXEL_V1_H


#include <cstdint>
#include <string>



class _base_Dynamixel_v1 {
public:

    enum class Error { // bit number
        INPUT_VOLTAGE_ERROR = 0,
        ANGLE_LIMIT_ERROR = 1,
        OVERHEATING_ERROR = 2,
        RANGE_ERROR = 3,
        CHECKSUM_ERROR = 4,
        OVERLOAD_ERROR = 5,
        INSTRUCTION_ERROR = 6
    };


    _base_Dynamixel_v1();

    uint32_t splitPackets(std::uint8_t const *inputBuffer, std::uint32_t inputLength, std::uint8_t **outputPackets, std::uint32_t maxNumberOfPackets, std::uint32_t maxNumberOfBytes);

    void resetSpliting(); // could be useful in timeouts

    static void pingEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID);
    static std::uint8_t statusResponse(std::uint8_t const *packet, std::uint8_t &ID);

    static std::uint8_t calculateChecksum(std::uint8_t const *packet);
    static bool validateChecksum(std::uint8_t const *packet, std::uint32_t maxPacketLength);

    static bool validatePacket(std::uint8_t const *packet, std::uint32_t maxPacketLength);

    static std::string errorsToString(std::uint8_t error);

private:

    std::uint8_t packet_[254] = {};
    std::uint8_t *const packetBegin_;
    std::uint8_t *const packetEnd_;

    std::uint8_t *ptrPacketCur_;
    std::uint8_t *ptrPacketBegin_;
    std::uint8_t *ptrPacketEnd_;

};


#endif //DYNAMIXEL__BASE_DYNAMIXEL_V1_H

