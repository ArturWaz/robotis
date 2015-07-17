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
    static void getPIDEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID);
    static std::uint8_t getPIDResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint8_t &P, std::uint8_t &I, std::uint8_t &D);


    static void getPresentPositionEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID);
    static std::uint8_t getPresentPositionResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint16_t &value);

    static void getPresentSpeedEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID);
    static std::uint8_t getPresentSpeedResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint16_t &value);

    static void getPresentLoadEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID);
    static std::uint8_t getPresentLoadResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint16_t &value);

    static void getPunchEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID);
    static std::uint8_t getPunchResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint16_t &value);

    static void getGoalPositionEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID);
    static std::uint8_t getGoalPositionResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint16_t &value);

    static void getMovingSpeedEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID);
    static std::uint8_t getMovingSpeedResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint16_t &value);


    static void getPresentVoltageEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID);
    static std::uint8_t getPresentVoltageResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint8_t &value);

    static void getPresentTemperatureEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID);
    static std::uint8_t getPresentTemperatureResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint8_t &value);

    static void getMovingEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID);
    static std::uint8_t getMovingResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint8_t &value);

    static void getGoalAccelerationEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID);
    static std::uint8_t getGoalAccelerationResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint8_t &value);

    static void getTorqueEnableEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID);
    static std::uint8_t getTorqueEnableResponse(std::uint8_t const *packet, std::uint8_t &ID, std::uint8_t &value);




    // WRITING TO SERVO
    static void setPIDEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID, std::uint8_t P,std::uint8_t I, std::uint8_t D);


    static void setGoalPositionEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID, std::uint16_t value);

    static void setMovingSpeedEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID, std::uint16_t value);

    static void setPunchEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID, std::uint16_t value);

    static void setTorqueLimitEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID, std::uint16_t value);


    static void setTorqueEnableEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID, std::uint8_t value);

    static void setGoalAccelerationEnquire(std::uint8_t *packet, std::uint32_t maxPacketLength, std::uint8_t ID, std::uint8_t value);


};


#endif //DYNAMIXEL_MX28_H
