//
// Created by geox on 15.07.15.
//

#ifndef _BASE_DYNAMIXEL_V1_H
#define _BASE_DYNAMIXEL_V1_H


#include <stdint.h>




class asynchronousPacketReader {
public:

    asynchronousPacketReader();

    uint32_t splitPackets(uint8_t const *inputBuffer, uint32_t inputLength, uint8_t **outputPackets, uint32_t maxNumberOfPackets, uint32_t maxNumberOfBytes);
    void resetSpliting(); // could be useful in timeouts

private:

    uint8_t packet_[254] = {};
    uint8_t *const packetBegin_;
    uint8_t *const packetEnd_;

    uint8_t *ptrPacketCur_;
    uint8_t *ptrPacketBegin_;
    uint8_t *ptrPacketEnd_;

};


#endif //DYNAMIXEL__BASE_DYNAMIXEL_V1_H

