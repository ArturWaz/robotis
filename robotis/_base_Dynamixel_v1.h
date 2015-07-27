//
// Created by geox on 15.07.15.
//

#ifndef _BASE_DYNAMIXEL_V1_H
#define _BASE_DYNAMIXEL_V1_H


#include <stdint.h>
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

    uint32_t splitPackets(uint8_t const *inputBuffer, uint32_t inputLength, uint8_t **outputPackets, uint32_t maxNumberOfPackets, uint32_t maxNumberOfBytes);
    void resetSpliting(); // could be useful in timeouts

    static void pingEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    static uint8_t statusResponse(uint8_t const *packet, uint8_t &ID);

    static uint8_t calculateChecksum(uint8_t const *packet);
    static bool validateChecksum(uint8_t const *packet, uint32_t maxPacketLength);

    static bool validatePacket(uint8_t const *packet, uint32_t maxPacketLength);

    static std::string errorsToString(uint8_t error);

private:

    uint8_t packet_[254] = {};
    uint8_t *const packetBegin_;
    uint8_t *const packetEnd_;

    uint8_t *ptrPacketCur_;
    uint8_t *ptrPacketBegin_;
    uint8_t *ptrPacketEnd_;

};


#endif //DYNAMIXEL__BASE_DYNAMIXEL_V1_H

