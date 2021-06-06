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
        memcpy(&gps_buff[buff_count],RX,1); 
        buff_count++;
        //Serial.print(buff_count);         
    } 
    else if (buff_count==1 && RX[0]==ubexheader[1])
    {
        Serial.print("HeaderFound");
        header_found=true;
        memcpy(&gps_buff[buff_count],RX,1); 
        buff_count++; 
        //Serial.print(buff_count);
                
    }
    else if(header_found&&buff_count<4)
    {
        memcpy(&gps_buff[buff_count],RX,1);        
        buff_count++;
        //Serial.print(buff_count);  
    }    

    else if(buff_count==4)
    {        
        memcpy(&gps_buff[buff_count],RX,1);
        memcpy(&readnum,RX,1);
        readnum=readnum+2;
        Serial.print(readnum);
        buff_count++;        
    }
    else if(buff_count>4&&readnum>0)
    {        
        memcpy(&gps_buff[buff_count],RX,1);
        readnum--;
        buff_count++;  
    }    
    else 
    {
        header_found=0;
        buff_count=0;
        readnum=0;
    }

}

bool GPS_Parse::checksum()
{
    return 0;
}
