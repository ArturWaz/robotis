//
// Created by geox on 15.07.15.
//

#include "MX28.h"

#include <stdexcept>






/*
 *  READING FROM SERVO
 */

#define GENERATE_SENDING_PACKET_FOR_READ(ADDRESS,LENGTH) \
    if (maxPacketLength < 8) throw std::range_error(" [ MX_28::sendPresentPosition(std::uint8_t *, std::uint32_t, std::uint8_t ID) ]: Packet length is too short.\n"); \
    packet[0] = 0xFF; \
    packet[1] = 0xFF; \
    packet[2] = ID; \
    packet[3] = 0x04; \
    packet[4] = 0x02; \
    packet[5] = ADDRESS; \
    packet[6] = LENGTH; \
    packet[7] = ~(ID+std::uint8_t(0x06+ADDRESS+LENGTH)); // checksum


#define GENERATE_PACKET_READER_1B() \
    ID = packet[2]; \
    value = packet[5]; \
    return packet[4];


#define GENERATE_PACKET_READER_2B() \
    ID = packet[2]; \
    value = packet[5] | (packet[6]<<8); \
    return packet[4];







void MX28::getPIDEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x1A,0x03) }
std::uint8_t MX28::getPIDResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint8_t &P, std::uint8_t &I, std::uint8_t &D) {
    ID = packet[2];
    D = packet[5];
    I = packet[6];
    P = packet[7];
    return packet[4];
}





void MX28::getPresentPositionEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x24,0x02) }
std::uint8_t MX28::getPresentPositionResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint16_t &value) {
    GENERATE_PACKET_READER_2B() }


void MX28::getPresentSpeedEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x26,0x02) }
std::uint8_t MX28::getPresentSpeedResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint16_t &value) {
    GENERATE_PACKET_READER_2B() }


void MX28::getPresentLoadEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x28,0x02) }
std::uint8_t MX28::getPresentLoadResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint16_t &value) {
    GENERATE_PACKET_READER_2B() }


void MX28::getPunchEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x30,0x02) }
std::uint8_t MX28::getPunchResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint16_t &value) {
    GENERATE_PACKET_READER_2B() }


void MX28::getGoalPositionEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x1E,0x02) }
std::uint8_t MX28::getGoalPositionResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint16_t &value) {
    GENERATE_PACKET_READER_2B() }


void MX28::getMovingSpeedEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x20,0x02) }
std::uint8_t MX28::getMovingSpeedResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint16_t &value) {
    GENERATE_PACKET_READER_2B() }





void MX28::getPresentVoltageEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x2A,0x01) }
std::uint8_t MX28::getPresentVoltageResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint8_t &value) {
    GENERATE_PACKET_READER_1B() }


void MX28::getPresentTemperatureEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x2B,0x01) }
std::uint8_t MX28::getPresentTemperatureResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint8_t &value) {
    GENERATE_PACKET_READER_1B() }


void MX28::getMovingEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x2E,0x01) }
std::uint8_t MX28::getMovingResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint8_t &value) {
    GENERATE_PACKET_READER_1B() }


void MX28::getGoalAccelerationEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x49,0x01) }
std::uint8_t MX28::getGoalAccelerationResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint8_t &value) {
    GENERATE_PACKET_READER_1B() }


void MX28::getTorqueEnableEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x18,0x01) }
std::uint8_t MX28::getTorqueEnableResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint8_t &value) {
    GENERATE_PACKET_READER_1B() }






/*
 *  WRITING TO SERVO
 */

