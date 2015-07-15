

#include "ft232r/FT232R.h"
#include "robotis/_base_Dynamixel_v1.h"


#include <cstdint>
#include <iostream>
#include <cstring>
#include <stdexcept>




using namespace std;

void show(std::uint8_t l) { cout << hex << "0x" << int(l) << " " << dec << endl; }








using namespace std;

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


void test() {

    std::uint8_t buf1[12] = {0x02, 0xFF, 0XFF, 0x01, 0x05, 0x03, 0x0C, 0x64, 0xAA, 0xDC, 0x54, 0x23};
    std::uint8_t buf2[12] = {0x53, 0x64, 0xFF, 0xFF, 0x01, 0x04, 0x02, 0x2B, 0x01, 0xCC, 0x43, 0x66};
    std::uint8_t buf3[24] = {0x53, 0x64, 0xFF, 0xFF, 0x01, 0x04, 0x02, 0x2B, 0x01, 0xCC, 0x43, 0x66, 0x02, 0xFF, 0XFF, 0x01, 0x05, 0x03, 0x0C, 0x64, 0xAA, 0xDC, 0x54, 0x23};
    _base_Dynamixel_v1 d;

    std::uint8_t **packets = new uint8_t*[20];
    for (int i = 0; i < 250; ++i)
        packets[i] = new uint8_t[250];

    std::uint32_t numOfPack;



    numOfPack = d.splitPackets(buf1,12,packets,20,250);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf1,12,packets,20,250);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }


    numOfPack = d.splitPackets(buf2,12,packets,20,250);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }

    numOfPack = d.splitPackets(buf3,24,packets,20,250);
    cout << "Number of read packets: " << numOfPack << endl;
    for (std::uint32_t i = 0; i < numOfPack; ++i) {
        printLine(packets[i],packets[i][3]+4);
    }

    cout << hex << int(_base_Dynamixel_v1::checksum(packets[0])) << dec << endl;
    cout << hex << int(_base_Dynamixel_v1::checksum(packets[1])) << dec << endl;

}

int main() {

    test();

    return 0;
}