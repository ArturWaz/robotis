//
// Created by geox on 15.07.15.
//

#ifndef DYNAMIXEL_MX28_H
#define DYNAMIXEL_MX28_H


#include "_base_communicationV1.h"


namespace MX28 {
/*
 *  http://support.robotis.com/en/product/dynamixel/mx_series/mx-28.htm
 */

    using namespace _base_communicationV1;

    // READING FROM SERVO
    void getPIDEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    uint8_t getPIDResponse(uint8_t const *packet, uint8_t &ID, uint8_t &P, uint8_t &I, uint8_t &D);
    inline uint32_t getPIDResponseLength() { return 0x09; }


    void getPresentPositionEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    uint8_t getPresentPositionResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value);
    inline uint32_t getPresentPositionResponseLength() { return 0x08; }

    void getPresentSpeedEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    uint8_t getPresentSpeedResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value);
    inline uint32_t getPresentSpeedResponseLength() { return 0x08; }

    void getPresentLoadEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    uint8_t getPresentLoadResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value);
    inline uint32_t getPresentLoadResponseLength() { return 0x08; }

    void getPunchEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    uint8_t getPunchResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value);
    inline uint32_t getPunchResponseLength() { return 0x08; }

    void getGoalPositionEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    uint8_t getGoalPositionResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value);
    inline uint32_t getGoalPositionResponseLength() { return 0x08; }

    void getMovingSpeedEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    uint8_t getMovingSpeedResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value);
    inline uint32_t getMovingSpeedResponseLength() { return 0x08; }


    void getPresentVoltageEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    uint8_t getPresentVoltageResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value);
    inline uint32_t getPresentVoltageResponseLength() { return 0x07; }

    void getPresentTemperatureEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    uint8_t getPresentTemperatureResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value);
    inline uint32_t getPresentTemperatureResponseLength() { return 0x07; }

    void getMovingEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    uint8_t getMovingResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value);
    inline uint32_t getMovingResponseLength() { return 0x07; }

    void getGoalAccelerationEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    uint8_t getGoalAccelerationResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value);
    inline uint32_t getGoalAccelerationResponseLength() { return 0x07; }

    void getTorqueEnableEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    uint8_t getTorqueEnableResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value);
    inline uint32_t getTorqueEnableResponseLength() { return 0x07; }




    // WRITING TO SERVO
    void setPIDEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint8_t P,uint8_t I, uint8_t D);


    void setGoalPositionEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint16_t value);

    void setMovingSpeedEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint16_t value);

    void setPunchEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint16_t value);

    void setTorqueLimitEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint16_t value);


    void setTorqueEnableEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint8_t value);

    void setGoalAccelerationEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint8_t value);


}


#endif //DYNAMIXEL_MX28_H
