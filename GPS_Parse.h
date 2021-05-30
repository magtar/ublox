#pragma once
#include "GPS_MSG.h"

class GPS_Parse
{
    public:
        GPS_Parse();
        ~GPS_Parse();
        void getc();
        short int buff_count;
        char gps_buff[255];

};

