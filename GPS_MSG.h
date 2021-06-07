#pragma once
#include "Arduino.h"
const char ubexheader []={0xB5, 0x62};
const char ubexecefmesg []={0x01, 0x01};
const char ubexnacmesg []={0x01, 0x02};

void parse (char *mesg);

struct ubexECEF
{
    unsigned int itow; // U4
    int ecefX; //i4
    int ecefY; //i4
    int ecefZ; //i4
    unsigned int pAcc; //u4
};

struct ubexNAVSOL
{
    unsigned int itow; // U4
    int ftow;
    short int week;
    unsigned char gpsFix;//U1
    char flags; //x1
    int ecefX; //i4
    int ecefY; //i4
    int ecefZ; //i4
    unsigned int pAcc; //u4
    int ecefVX; //i4
    int ecefVY; //i4
    int ecefVZ; //i4
    unsigned int sAcc; //u4
    unsigned short pDOP;//u2
    unsigned char reserved1; //U1
    unsigned char numSV; //U1
    unsigned int resrved2; //u4
};

struct ubexNAVPVT
{
    uint32_t itow;
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    char valid;
    uint32_t tAcc;
    int32_t nano;
    uint8_t fixType;
    char flags;
    char flags2;
    uint8_t numSV;
    int32_t lon;
    int32_t lat;
    int32_t height;
    int32_t hMSL;
    uint32_t hAcc;
    uint32_t vAcc;
    int32_t velN;
    int32_t velE;
    int32_t velD;
    int32_t gSpeed;
    int32_t headMot;
    uint32_t sAcc;
    uint32_t headAcc;
    uint16_t pDOP;
    char flags3;
    uint8_t reserved1;
    int32_t headVeh;
    int16_t magDec;
    uint16_t magAcc;    
};

