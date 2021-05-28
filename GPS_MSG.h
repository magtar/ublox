#pragma once
//const char ubexheader []={0xB5, 0x62};
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

struct ubexNAV
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


