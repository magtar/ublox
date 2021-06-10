#pragma once
#include "GPS_MSG.h"
#include "Arduino.h"
#include "mbed.h"

class GPS_Parse
{
    public:
        GPS_Parse(char *rx_buffer);
        ~GPS_Parse();
        void getc();
        void checksum();
        bool header_found;
        short int buff_count;
        char gps_buff[255];
        char *RX;
        uint16_t payloadLen;
        uint16_t readnum;
        uint8_t CK_A;
        uint8_t CK_B;
};

