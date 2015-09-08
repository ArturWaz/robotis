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
    void getPIDEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept;
    uint8_t getPIDResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint8_t &P, uint8_t &I, uint8_t &D) noexcept;
    inline uint32_t getPIDResponseLength() noexcept { return 0x09; }


    void getPresentPositionEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept;
    uint8_t getPresentPositionResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint16_t &value) noexcept;
    inline uint32_t getPresentPositionResponseLength() noexcept { return 0x08; }

    void getPresentSpeedEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept;
    uint8_t getPresentSpeedResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint16_t &value) noexcept;
    inline uint32_t getPresentSpeedResponseLength() noexcept { return 0x08; }

    void getPresentLoadEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept;
    uint8_t getPresentLoadResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint16_t &value) noexcept;
    inline uint32_t getPresentLoadResponseLength() noexcept { return 0x08; }

    void getPunchEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept;
    uint8_t getPunchResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint16_t &value) noexcept;
    inline uint32_t getPunchResponseLength() noexcept { return 0x08; }

    void getGoalPositionEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept;
    uint8_t getGoalPositionResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint16_t &value) noexcept;
    inline uint32_t getGoalPositionResponseLength() noexcept { return 0x08; }

    void getMovingSpeedEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept;
    uint8_t getMovingSpeedResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint16_t &value) noexcept;
    inline uint32_t getMovingSpeedResponseLength() noexcept { return 0x08; }


    void getPresentVoltageEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept;
    uint8_t getPresentVoltageResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint8_t &value) noexcept;
    inline uint32_t getPresentVoltageResponseLength() noexcept { return 0x07; }

    void getPresentTemperatureEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept;
    uint8_t getPresentTemperatureResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint8_t &value) noexcept;
    inline uint32_t getPresentTemperatureResponseLength() noexcept { return 0x07; }

    void getMovingEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept;
    uint8_t getMovingResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint8_t &value) noexcept;
    inline uint32_t getMovingResponseLength() noexcept { return 0x07; }

    void getGoalAccelerationEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept;
    uint8_t getGoalAccelerationResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint8_t &value) noexcept;
    inline uint32_t getGoalAccelerationResponseLength() noexcept { return 0x07; }

    void getTorqueEnableEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID) noexcept;
    uint8_t getTorqueEnableResponse(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> const &packet, uint8_t &ID, uint8_t &value) noexcept;
    inline uint32_t getTorqueEnableResponseLength() noexcept { return 0x07; }




    // WRITING TO SERVO
    void setPIDEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint8_t P,uint8_t I, uint8_t D) noexcept;


    void setGoalPositionEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint16_t value) noexcept;

    void setMovingSpeedEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint16_t value) noexcept;

    void setPunchEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint16_t value) noexcept;

    void setTorqueLimitEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint16_t value) noexcept;


    void setTorqueEnableEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint8_t value) noexcept;

    void setGoalAccelerationEnquire(std::array<uint8_t, ROBOTIS_BUFFER_LENGTH> &packet, uint8_t ID, uint8_t value) noexcept;


}


#endif //DYNAMIXEL_MX28_H
