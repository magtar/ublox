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
        //Serial.print(readnum);     
    }
    else if(buff_count>5&&readnum!=0)
    {        
        memcpy(&gps_buff[buff_count],RX,1);
        readnum--;
        buff_count++;        
        if(readnum==0)
        {
             checksum(); 
            header_found=false;
            buff_count=0;
            readnum=0;
            payloadLen=0;
           
            memset(&gps_buff,0,sizeof(gps_buff));
            
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

void GPS_Parse::checksum()
{
    CK_A=0;
    CK_B=0;
    uint16_t N=payloadLen+6;
    //uint16_t N=payloadLen+1;
    for (uint16_t i=2;i<N;i++)
    {
        CK_A=CK_A+gps_buff[i];
        CK_B=CK_B+CK_A;       
    }
    if (CK_A==gps_buff[payloadLen+6] && CK_B==gps_buff[payloadLen+7])
    {
        Serial.print("yes");
    }
    else
    {     
        char buff[20];
        sprintf(buff,"%d,%d,%d,%d\n ",CK_A,gps_buff[payloadLen+6],CK_B,gps_buff[payloadLen+7]);
        Serial.print(buff);
    }
}
