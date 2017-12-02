#include "DsRTC.h"

#define ADDR  0xD0

DsRTC::DsRTC() : i2c(PTE25, PTE24){

}

int DsRTC::getHours(){
    char cmd = 0x02;
    return getRegVal(cmd);
}

int DsRTC::getMinutes(){
    char cmd = 0x01;
    return getRegVal(cmd);
}

int DsRTC::getSeconds(){
    char cmd = 0x00;
    return getRegVal(cmd);
}

int DsRTC::getMilliseconds(){
    return 0;
}

int DsRTC::bcdToDec(int val) {
    return ( (val/16*10) + (val%16) );
}

int DsRTC::getRegVal(char addr){
    char data;
    char cmd;
    cmd = addr;
    i2c.write(ADDR, &cmd, 1 );
    i2c.read(ADDR, &data, 1 );
    return(bcdToDec(data));
}
