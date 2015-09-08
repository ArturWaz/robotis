

#include "robotis/asynchronousPacketReader.h"
#include "robotis/MX12W.h"


#include <cstdint>
#include <stdint.h>
#include <iostream>
#include <cstring>
#include <stdexcept>


using namespace std;

void show(std::uint8_t l) { cout << hex << "0x" << int(l) << " " << dec << endl; }


template <class T>
void printLine(T const *b, std::uint32_t length) {
    cout << "Line:   [ ";
    for (uint32_t i = 0; i < length; ++i) {
        cout << b[i];
    }
    cout << " ].\n";
}


void printLine(std::uint8_t const *b, std::uint32_t length) {
    cout << "Line:   [ " << hex;
    for (uint32_t i = 0; i < length; ++i) {
        cout << "0x" << int(b[i]) << " ";
    }
    cout << dec << "].\n";
}


void printLine(array<uint8_t,ROBOTIS_BUFFER_LENGTH> const &b, std::uint32_t length) {
    cout << "Line:   [ " << hex;
    for (uint32_t i = 0; i < length; ++i) {
        cout << "0x" << int(b[i]) << " ";
    }
    cout << dec << "].\n";
}


void printPacket(std::uint8_t const *b) {
    cout << "Line:   [ " << hex;
    for (uint32_t i = 0; i < b[3]+uint32_t(4); ++i) {
        cout << "0x" << int(b[i]) << " ";
    }
    cout << dec << "].\n";
}


void printPacket(array<uint8_t,ROBOTIS_BUFFER_LENGTH> const &b) {
    cout << "Line:   [ " << hex;
    for (uint32_t i = 0; i < b[3]+uint32_t(4); ++i) {
        cout << "0x" << int(b[i]) << " ";
    }
    cout << dec << "].\n";
}


void test_base_Dynamixel_v1() {

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

    asynchronousPacketReader d;

    array<uint8_t,ROBOTIS_BUFFER_LENGTH> packets[20];
    //for (int i = 0; i < 250; ++i)
    //    packets[i] = new uint8_t[250];

    std::uint32_t numOfPack;



    numOfPack = d.splitPackets(buf1,12,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf1,12,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf2,12,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }

    numOfPack = d.splitPackets(buf3,24,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    cout << "Checksum: " << hex << int(MX28::calculateChecksum(packets[0])) << ", validate checksum: " << MX28::validateChecksum(packets[0]) << ", validate packet: " << MX28::validatePacket(packets[0]) << dec << endl;
    cout << "Checksum: " << hex << int(MX28::calculateChecksum(packets[1])) << ", validate checksum: " << MX28::validateChecksum(packets[1]) << ", validate packet: " << MX28::validatePacket(packets[1]) << dec << endl;

    numOfPack = d.splitPackets(buf4,6,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf5,6,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf6,1,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf7,1,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf8,1,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf9,1,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf10,1,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf11,1,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf12,1,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf13,1,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf14,1,packets,20);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }

}





void test_MX28() {

    array<uint8_t,ROBOTIS_BUFFER_LENGTH> packet;

    MX28::getPresentPositionEnquire(packet, 1);

    printPacket(packet);

    cout << "Packet validation: " << (MX28::validatePacket(packet)?"good":"bad") << endl;
    cout << "Checksum validation: " << (MX28::validateChecksum(packet)?"good":"bad") << endl;

    uint8_t ID;
    uint16_t value;

    cout << hex << int(MX28::getPresentPositionResponse(packet, ID, value)) << endl;
    cout << int(ID) << "   " << value << dec << endl;

    cout << MX28::errorsToString(0xFF);

}



int main() {

    //test_base_Dynamixel_v1();
    test_MX28();






    return 0;
}
