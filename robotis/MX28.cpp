//
// Created by geox on 15.07.15.
//

#include "MX28.h"

#include <stdexcept>






/*
 *  READING FROM SERVO
 */

#define GENERATE_SENDING_PACKET_FOR_READ(ADDRESS,LENGTH) \
    if (maxPacketLength < 10) throw std::range_error(" [ MX_28::...(uint8_t *, uint32_t, uint8_t ID) ]: Packet length is too short.\n"); \
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







void MX28::getPIDEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x1A,0x03) }
uint8_t MX28::getPIDResponse(uint8_t const *packet, uint8_t &ID, uint8_t &P, uint8_t &I, uint8_t &D) {
    ID = packet[2];
    D = packet[5];
    I = packet[6];
    P = packet[7];
    return packet[4];
}




void MX28::getPresentPositionEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x24,0x02) }
uint8_t MX28::getPresentPositionResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value) {
    GENERATE_PACKET_READER_2B() }


void MX28::getPresentSpeedEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x26,0x02) }
uint8_t MX28::getPresentSpeedResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value) {
    GENERATE_PACKET_READER_2B() }


void MX28::getPresentLoadEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x28,0x02) }
uint8_t MX28::getPresentLoadResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value) {
    GENERATE_PACKET_READER_2B() }


void MX28::getPunchEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x30,0x02) }
uint8_t MX28::getPunchResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value) {
    GENERATE_PACKET_READER_2B() }


void MX28::getGoalPositionEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x1E,0x02) }
uint8_t MX28::getGoalPositionResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value) {
    GENERATE_PACKET_READER_2B() }


void MX28::getMovingSpeedEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x20,0x02) }
uint8_t MX28::getMovingSpeedResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value) {
    GENERATE_PACKET_READER_2B() }





void MX28::getPresentVoltageEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x2A,0x01) }
uint8_t MX28::getPresentVoltageResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value) {
    GENERATE_PACKET_READER_1B() }


void MX28::getPresentTemperatureEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x2B,0x01) }
uint8_t MX28::getPresentTemperatureResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value) {
    GENERATE_PACKET_READER_1B() }


void MX28::getMovingEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x2E,0x01) }
uint8_t MX28::getMovingResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value) {
    GENERATE_PACKET_READER_1B() }


void MX28::getGoalAccelerationEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x49,0x01) }
uint8_t MX28::getGoalAccelerationResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value) {
    GENERATE_PACKET_READER_1B() }


void MX28::getTorqueEnableEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID) {
    GENERATE_SENDING_PACKET_FOR_READ(0x18,0x01) }
uint8_t MX28::getTorqueEnableResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value) {
    GENERATE_PACKET_READER_1B() }






/*
 *  WRITING TO SERVO
 */


#define GENERATE_SENDING_PACKET_FOR_WRITE_1B(ADDRESS) \
    if (maxPacketLength < 10) throw std::range_error(" [ MX_28::...(uint8_t *, uint32_t, uint8_t, uint8_t) ]: Packet length is too short.\n"); \
    packet[0] = 0xFF; \
    packet[1] = 0xFF; \
    packet[2] = ID; \
    packet[3] = 0x04; \
    packet[4] = 0x02; \
    packet[5] = ADDRESS; \
    packet[6] = value; \
    packet[7] = ~(ID+value+uint8_t(0x06+ADDRESS)); // checksum


#define GENERATE_SENDING_PACKET_FOR_WRITE_2B(ADDRESS) \
if (maxPacketLength < 10) throw std::range_error(" [ MX_28::...(uint8_t *, uint32_t, uint8_t, uint16_t) ]: Packet length is too short.\n"); \
    packet[0] = 0xFF; \
    packet[1] = 0xFF; \
    packet[2] = ID; \
    packet[3] = 0x04; \
    packet[4] = 0x03; \
    packet[5] = ADDRESS; \
    packet[6] = value; \
    packet[7] = (value>>8); \
    packet[8] = ~(ID+(*(packet+6))+(*(packet+7))+uint8_t(0x07+ADDRESS)); // checksum






void MX28::setPIDEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint8_t P, uint8_t I, uint8_t D) {
    if (maxPacketLength < 10) throw std::range_error(" [ MX_28::...(uint8_t *, uint32_t, uint8_t ID) ]: Packet length is too short.\n");
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



void MX28::setGoalPositionEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint16_t value) {
    GENERATE_SENDING_PACKET_FOR_WRITE_2B(0x1E) }

void MX28::setMovingSpeedEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint16_t value) {
    GENERATE_SENDING_PACKET_FOR_WRITE_2B(0x20) }

void MX28::setPunchEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint16_t value) {
    GENERATE_SENDING_PACKET_FOR_WRITE_2B(0x30) }

void MX28::setTorqueLimitEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint16_t value) {
    GENERATE_SENDING_PACKET_FOR_WRITE_2B(0x22) }



void MX28::setTorqueEnableEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint8_t value) {
    GENERATE_SENDING_PACKET_FOR_WRITE_1B(0x18) }

void MX28::setGoalAccelerationEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint8_t value) {
    GENERATE_SENDING_PACKET_FOR_WRITE_1B(0x49) }
