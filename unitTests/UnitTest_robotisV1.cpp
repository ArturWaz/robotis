//
// Created by geox on 12.10.15.
//

#ifndef DYNAMIXEL_UNITTEST_ROBOTIS_H
#define DYNAMIXEL_UNITTEST_ROBOTIS_H


#include "../robotis/MX12W.h"
#include "../robotis/PacketSplitter_robotisV1.h"


#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE robotisV1
#include <boost/test/unit_test.hpp>


struct UnitTest_robotisV1 {
    UnitTest_robotisV1() { BOOST_TEST_MESSAGE( "Setup UnitTest_robotisV1 fixture." ); } // setup fixture
    ~UnitTest_robotisV1() { BOOST_TEST_MESSAGE( "Teardown UnitTest_robotisV1 fixture." ); } // teardown fixture

    PacketSplitter_robotisV1 packetSplitter;
    std::array<uint8_t,ROBOTIS_BUFFER_LENGTH> buffer[50];

    std::uint8_t buf1[12] = {0x02, 0xFF, 0XFF, 0x01, 0x05, 0x03, 0x0C, 0x64, 0xAA, 0xDC, 0x54, 0x23};
    std::uint8_t buf2[12] = {0x53, 0x64, 0xFF, 0xFF, 0x01, 0x04, 0x02, 0x2B, 0x01, 0xCC, 0x43, 0x66};
    std::uint8_t buf3[24] = {0x53, 0x64, 0xFF, 0xFF, 0x01, 0x04, 0x02, 0x2B, 0x01, 0xCC, 0x43, 0x66, 0x02, 0xFF, 0XFF, 0x01, 0x05, 0x03, 0x0C, 0x64, 0xAA, 0xDC, 0x54, 0x23};
    std::uint8_t buf4[6] = {0x02, 0xFF, 0XFF, 0x01, 0x05, 0x03};
    std::uint8_t buf5[6] = {0x0C, 0x64, 0xAA, 0xDC, 0x54, 0x23};

    std::uint8_t buf6[1] = {0xFF};
    std::uint8_t buf7[1] = {0xFF};
    std::uint8_t buf8[1] = {0x01};
    std::uint8_t buf9[1] = {0x05};
    std::uint8_t buf10[1] = {0x03};
    std::uint8_t buf11[1] = {0x0C};
    std::uint8_t buf12[1] = {0x64};
    std::uint8_t buf13[1] = {0xAA};
    std::uint8_t buf14[1] = {0xDC};

};


BOOST_FIXTURE_TEST_SUITE(RobotisV1,UnitTest_robotisV1)

BOOST_AUTO_TEST_CASE(Test_PacketSplitter_robotisV1) {
    BOOST_CHECK(packetSplitter.splitPackets(buf1,12,buffer,50) == 1);
    BOOST_CHECK(packetSplitter.splitPackets(buf2,12,buffer,50) == 1);
    BOOST_CHECK(packetSplitter.splitPackets(buf3,24,buffer,50) == 2);
    BOOST_CHECK(packetSplitter.splitPackets(buf4,6,buffer,50) == 0);
    BOOST_CHECK(packetSplitter.splitPackets(buf5,6,buffer,50) == 1);
    BOOST_CHECK(packetSplitter.splitPackets(buf6,1,buffer,50) == 0);
    BOOST_CHECK(packetSplitter.splitPackets(buf7,1,buffer,50) == 0);
    BOOST_CHECK(packetSplitter.splitPackets(buf8,1,buffer,50) == 0);
    BOOST_CHECK(packetSplitter.splitPackets(buf9,1,buffer,50) == 0);
    BOOST_CHECK(packetSplitter.splitPackets(buf10,1,buffer,50) == 0);
    BOOST_CHECK(packetSplitter.splitPackets(buf11,1,buffer,50) == 0);
    BOOST_CHECK(packetSplitter.splitPackets(buf12,1,buffer,50) == 0);
    BOOST_CHECK(packetSplitter.splitPackets(buf13,1,buffer,50) == 0);
    BOOST_CHECK(packetSplitter.splitPackets(buf14,1,buffer,50) == 1);

    packetSplitter.resetSpliting();
    BOOST_CHECK_MESSAGE(packetSplitter.splitPackets(buf3,24,buffer,50) == 2, "PacketSplitter_robotisV1::resteSplitteing(): problem.");
}

BOOST_AUTO_TEST_CASE(TEST_base_communicationV1) {
    BOOST_CHECK(packetSplitter.splitPackets(buf1,12,buffer,50) == 1);
    BOOST_CHECK(_base_communicationV1::validatePacket(buffer[0]));
    BOOST_CHECK(_base_communicationV1::validateChecksum(buffer[0]));
    BOOST_CHECK(_base_communicationV1::calculateChecksum(buffer[0]) == 0xDC);
}

BOOST_AUTO_TEST_SUITE_END()


#endif //DYNAMIXEL_UNITTEST_ROBOTIS_H
