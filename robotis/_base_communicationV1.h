//
// Created by geox on 07.08.15.
//

#ifndef DYNAMIXEL__BASE_DYNAMIXELCOMMUNICATIONV1_H
#define DYNAMIXEL__BASE_DYNAMIXELCOMMUNICATIONV1_H


#define ROBOTIS_BUFFER_LENGTH 256 // default: 256, rather do not modify


#include <stdint.h>
#include <string>
#include <array>


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

    void pingEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept;
    uint8_t statusResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID) noexcept;
    inline uint32_t statusResponseLength() noexcept { return 0x06; }


    uint8_t calculateChecksum(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet) noexcept;
    bool validateChecksum(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet) noexcept;

    bool validatePacket(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet) noexcept;

    std::string errorsToString(uint8_t error) noexcept;

}


#endif //DYNAMIXEL__BASE_DYNAMIXELCOMMUNICATIONV1_H
