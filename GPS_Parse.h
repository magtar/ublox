#pragma once
#include "GPS_MSG.h"
#include "Arduino.h"

class GPS_Parse
{
    public:
        GPS_Parse(char *rx_buffer);
        ~GPS_Parse();
        void getc();
        bool checksum();
        bool header_found;
        short int buff_count;
        char gps_buff[255];
        char *RX;
        uint16_t payloadLen;
        uint8_t readnum;
        uint8_t CK_A;
        uint8_t CK_B;
};

