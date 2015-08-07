//
// Created by geox on 07.08.15.
//

#ifndef DYNAMIXEL__BASE_DYNAMIXELCOMMUNICATIONV1_H
#define DYNAMIXEL__BASE_DYNAMIXELCOMMUNICATIONV1_H


#include <stdint.h>
#include <string>


namespace _base_communicationV1 {
    
    enum class Error { // bit number
        INPUT_VOLTAGE_ERROR = 0,
        ANGLE_LIMIT_ERROR = 1,
        OVERHEATING_ERROR = 2,
        RANGE_ERROR = 3,
        CHECKSUM_ERROR = 4,
        OVERLOAD_ERROR = 5,
        INSTRUCTION_ERROR = 6
    };

    void pingEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    uint8_t statusResponse(uint8_t const *packet, uint8_t &ID);
    inline uint32_t statusResponseLength() { return 0x06; }


    uint8_t calculateChecksum(uint8_t const *packet);
    bool validateChecksum(uint8_t const *packet, uint32_t maxPacketLength);

    bool validatePacket(uint8_t const *packet, uint32_t maxPacketLength);

    std::string errorsToString(uint8_t error);

}


#endif //DYNAMIXEL__BASE_DYNAMIXELCOMMUNICATIONV1_H
