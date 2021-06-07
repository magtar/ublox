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
        header_found=true;
        memcpy(&gps_buff[buff_count],RX,1); 
        buff_count++;                 
    }
    else if(header_found&&buff_count<5)
    {
        memcpy(&gps_buff[buff_count],RX,1);        
        buff_count++;        
    }    

    else if(buff_count==5) 
    {        
        memcpy(&gps_buff[buff_count],RX,1);
        memcpy(&payloadLen,&gps_buff[buff_count-1],2);        
        readnum=payloadLen+2;        
        buff_count++;        
    }
    else if(buff_count>5&&readnum!=0)
    {        
        memcpy(&gps_buff[buff_count],RX,1);
        readnum--;
        buff_count++;        
        if(readnum==0)
        {
            header_found=false;
            buff_count=0;
            readnum=0;
            payloadLen=0;
            memset(&gps_buff,0,sizeof(gps_buff));
            checksum(); 
        }
    }    
    else 
    {
        header_found=false;
        buff_count=0;
        readnum=0;
        payloadLen=0;
        memset(&gps_buff,0,sizeof(gps_buff));
    }

}

bool GPS_Parse::checksum()
{
    CK_A=0;
    CK_B=0;
//     for (int i=0;i<N;i++)
//     {
//         CK_A=CK_A+buffer[i];
//         CK_B=CK_B+CK_A;
//     }
}
