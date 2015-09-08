//
// Created by geox on 15.07.15.
//

#include "MX28.h"







/*
 *  READING FROM SERVO
 */

#define GENERATE_SENDING_PACKET_FOR_READ(ADDRESS,LENGTH) \
    packet[0] = 0xFF; \
    packet[1] = 0xFF; \
    packet[2] = ID; \
    packet[3] = 0x04; \
    packet[4] = 0x02; \
    packet[5] = ADDRESS; \
    packet[6] = LENGTH; \
    packet[7] = ~(ID+uint8_t(0x06+ADDRESS+LENGTH)); // checksum


#define GENERATE_PACKET_READER_1B() \
    ID = packet[2]; \
    value = packet[5]; \
    return packet[4];


#define GENERATE_PACKET_READER_2B() \
    ID = packet[2]; \
    value = packet[5] | (packet[6]<<8); \
    return packet[4];







void MX28::getPIDEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept {
    GENERATE_SENDING_PACKET_FOR_READ(0x1A,0x03) }
uint8_t MX28::getPIDResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint8_t &P, uint8_t &I, uint8_t &D) noexcept {
    ID = packet[2];
    D = packet[5];
    I = packet[6];
    P = packet[7];
    return packet[4];
}




void MX28::getPresentPositionEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept {
    GENERATE_SENDING_PACKET_FOR_READ(0x24,0x02) }
uint8_t MX28::getPresentPositionResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint16_t &value) noexcept {
    GENERATE_PACKET_READER_2B() }


void MX28::getPresentSpeedEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept {
    GENERATE_SENDING_PACKET_FOR_READ(0x26,0x02) }
uint8_t MX28::getPresentSpeedResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint16_t &value) noexcept {
    GENERATE_PACKET_READER_2B() }


void MX28::getPresentLoadEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept {
    GENERATE_SENDING_PACKET_FOR_READ(0x28,0x02) }
uint8_t MX28::getPresentLoadResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint16_t &value) noexcept {
    GENERATE_PACKET_READER_2B() }


void MX28::getPunchEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept {
    GENERATE_SENDING_PACKET_FOR_READ(0x30,0x02) }
uint8_t MX28::getPunchResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint16_t &value) noexcept {
    GENERATE_PACKET_READER_2B() }


void MX28::getGoalPositionEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept {
    GENERATE_SENDING_PACKET_FOR_READ(0x1E,0x02) }
uint8_t MX28::getGoalPositionResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint16_t &value) noexcept {
    GENERATE_PACKET_READER_2B() }


void MX28::getMovingSpeedEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept {
    GENERATE_SENDING_PACKET_FOR_READ(0x20,0x02) }
uint8_t MX28::getMovingSpeedResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint16_t &value) noexcept {
    GENERATE_PACKET_READER_2B() }





void MX28::getPresentVoltageEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept {
    GENERATE_SENDING_PACKET_FOR_READ(0x2A,0x01) }
uint8_t MX28::getPresentVoltageResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint8_t &value) noexcept {
    GENERATE_PACKET_READER_1B() }


void MX28::getPresentTemperatureEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept {
    GENERATE_SENDING_PACKET_FOR_READ(0x2B,0x01) }
uint8_t MX28::getPresentTemperatureResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint8_t &value) noexcept {
    GENERATE_PACKET_READER_1B() }


void MX28::getMovingEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept {
    GENERATE_SENDING_PACKET_FOR_READ(0x2E,0x01) }
uint8_t MX28::getMovingResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint8_t &value) noexcept {
    GENERATE_PACKET_READER_1B() }


void MX28::getGoalAccelerationEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept {
    GENERATE_SENDING_PACKET_FOR_READ(0x49,0x01) }
uint8_t MX28::getGoalAccelerationResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint8_t &value) noexcept {
    GENERATE_PACKET_READER_1B() }


void MX28::getTorqueEnableEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept {
    GENERATE_SENDING_PACKET_FOR_READ(0x18,0x01) }
uint8_t MX28::getTorqueEnableResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint8_t &value) noexcept {
    GENERATE_PACKET_READER_1B() }






/*
 *  WRITING TO SERVO
 */


#define GENERATE_SENDING_PACKET_FOR_WRITE_1B(ADDRESS) \
    packet[0] = 0xFF; \
    packet[1] = 0xFF; \
    packet[2] = ID; \
    packet[3] = 0x04; \
    packet[4] = 0x02; \
    packet[5] = ADDRESS; \
    packet[6] = value; \
    packet[7] = ~(ID+value+uint8_t(0x06+ADDRESS)); // checksum


#define GENERATE_SENDING_PACKET_FOR_WRITE_2B(ADDRESS) \
    packet[0] = 0xFF; \
    packet[1] = 0xFF; \
    packet[2] = ID; \
    packet[3] = 0x04; \
    packet[4] = 0x03; \
    packet[5] = ADDRESS; \
    packet[6] = value; \
    packet[7] = (value>>8); \
    packet[8] = ~(ID+(*(packet.data()+6))+(*(packet.data()+7))+(0x07+ADDRESS)); // checksum






void MX28::setPIDEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint8_t P, uint8_t I, uint8_t D) noexcept {
    packet[0] = 0xFF;
    packet[1] = 0xFF;
    packet[2] = ID;
    packet[3] = 0x04;
    packet[4] = 0x04;
    packet[5] = 0x1A;
    packet[6] = D;
    packet[7] = I;
    packet[8] = P;
    packet[9] = ~(ID+P+I+D+uint8_t(0x22)); // checksum
}



void MX28::setGoalPositionEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint16_t value) noexcept {
    GENERATE_SENDING_PACKET_FOR_WRITE_2B(0x1E) }

void MX28::setMovingSpeedEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint16_t value) noexcept {
    GENERATE_SENDING_PACKET_FOR_WRITE_2B(0x20) }

void MX28::setPunchEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint16_t value) noexcept {
    GENERATE_SENDING_PACKET_FOR_WRITE_2B(0x30) }

void MX28::setTorqueLimitEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint16_t value) noexcept {
    GENERATE_SENDING_PACKET_FOR_WRITE_2B(0x22) }



void MX28::setTorqueEnableEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint8_t value) noexcept {
    GENERATE_SENDING_PACKET_FOR_WRITE_1B(0x18) }

void MX28::setGoalAccelerationEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint8_t value) noexcept {
    GENERATE_SENDING_PACKET_FOR_WRITE_1B(0x49) }
