//
// Created by geox on 15.07.15.
//

#ifndef DYNAMIXEL_MX28_H
#define DYNAMIXEL_MX28_H


#include "_base_Dynamixel_v1.h"




class MX28: public _base_Dynamixel_v1 {
/*
 *  http://support.robotis.com/en/product/dynamixel/mx_series/mx-28.htm
 */
public:


    // READING FROM SERVO
    static void getPIDEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    static uint8_t getPIDResponse(uint8_t const *packet, uint8_t &ID, uint8_t &P, uint8_t &I, uint8_t &D);


    static void getPresentPositionEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    static uint8_t getPresentPositionResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value);

    static void getPresentSpeedEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    static uint8_t getPresentSpeedResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value);

    static void getPresentLoadEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    static uint8_t getPresentLoadResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value);

    static void getPunchEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    static uint8_t getPunchResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value);

    static void getGoalPositionEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    static uint8_t getGoalPositionResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value);

    static void getMovingSpeedEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    static uint8_t getMovingSpeedResponse(uint8_t const *packet, uint8_t &ID, uint16_t &value);


    static void getPresentVoltageEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    static uint8_t getPresentVoltageResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value);

    static void getPresentTemperatureEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    static uint8_t getPresentTemperatureResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value);

    static void getMovingEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    static uint8_t getMovingResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value);

    static void getGoalAccelerationEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    static uint8_t getGoalAccelerationResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value);

    static void getTorqueEnableEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID);
    static uint8_t getTorqueEnableResponse(uint8_t const *packet, uint8_t &ID, uint8_t &value);




    // WRITING TO SERVO
    static void setPIDEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint8_t P,uint8_t I, uint8_t D);


    static void setGoalPositionEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint16_t value);

    static void setMovingSpeedEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint16_t value);

    static void setPunchEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint16_t value);

    static void setTorqueLimitEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint16_t value);


    static void setTorqueEnableEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint8_t value);

    static void setGoalAccelerationEnquire(uint8_t *packet, uint32_t maxPacketLength, uint8_t ID, uint8_t value);


};


#endif //DYNAMIXEL_MX28_H
