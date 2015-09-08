//
// Created by geox on 07.08.15.
//



#include "_base_communicationV1.h"

#include <stdexcept>



void _base_communicationV1::pingEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept {
    packet[0] = 0xFF;
    packet[1] = 0xFF;
    packet[2] = ID;
    packet[3] = 0x02;
    packet[4] = 0x01;
    packet[5] = ~(ID+uint8_t(0x03));
}


uint8_t _base_communicationV1::statusResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID) noexcept {
    ID = packet[2];
    return packet[4];
}


uint8_t _base_communicationV1::calculateChecksum(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet) noexcept {
    uint8_t checksum = 0;
    for (uint8_t const *ptr = packet.data()+2; ptr != packet.data()+3+(*(packet.data()+3)); ++ptr) checksum += *ptr;
    return ~checksum;
}


bool _base_communicationV1::validateChecksum(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet) noexcept {
    uint8_t checksum = 0;
    for (uint8_t const *ptr = packet.data()+2; ptr != packet.data()+3+(*(packet.data()+3)); ++ptr) checksum += *ptr;
    return *(packet.data()+3+(*(packet.data()+3))) == uint8_t(~checksum);
}


bool _base_communicationV1::validatePacket(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet) noexcept {
    if (*packet.data() != 0xFF && *(packet.data()+1) != 0xFF) return false;
    uint8_t checksum = 0;
    for (uint8_t const *ptr = packet.data()+2; ptr != packet.data()+3+(*(packet.data()+3)); ++ptr) checksum += *ptr;
    return *(packet.data()+3+(*(packet.data()+3))) == uint8_t(~checksum);
}


std::string _base_communicationV1::errorsToString(uint8_t error) noexcept {
    std::string errorS("Error status: ");
    if (!error) return errorS + std::string("No errors.\n");
    if (error & (1<<int(Error::ANGLE_LIMIT_ERROR)))     errorS += std::string("\n    * Goal Position is written out of the range from CW Angle Limit to CCW Angle Limit.\n");
    if (error & (1<<int(Error::CHECKSUM_ERROR)))        errorS += std::string("    * The Checksum of the transmitted Instruction Packet is incorrect.\n");
    if (error & (1<<int(Error::INPUT_VOLTAGE_ERROR)))   errorS += std::string("    * Applied voltage is out of range of operating voltage.\n");
    if (error & (1<<int(Error::INSTRUCTION_ERROR)))     errorS += std::string("    * Sent undefined instruction.\n");
    if (error & (1<<int(Error::OVERHEATING_ERROR)))     errorS += std::string("    * Internal temperature of Dynamixel is out of the range.\n");
    if (error & (1<<int(Error::OVERLOAD_ERROR)))        errorS += std::string("    * The current load cannot be controlled by the set Torque.\n");
    if (error & (1<<int(Error::RANGE_ERROR)))           errorS += std::string("    * A command is out of the range for use.\n");
    return errorS;
}

