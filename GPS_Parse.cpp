#include "GPS_Parse.h"

GPS_Parse::GPS_Parse(char *rxbuffer)
{
    RX=rxbuffer;
    buff_count=0;
    header_found=false;
}

GPS_Parse::~GPS_Parse()
{
}

void GPS_Parse::getc()
{    
    if(RX[0]==ubexheader[0]&& buff_count==0)
    {
        //buff_count=0;
        memcpy(&gps_buff[buff_count],RX,1); 
        buff_count++;       
        Serial.print(buff_count);
    } 
}

bool GPS_Parse::checksum()
{
    return 0;
}
