#pragma once

#include "mbed.h"
#include "I2C.h"

class DsRTC
{
    protected:
    I2C i2c;

    public:
    DsRTC();

    int getHours();
    int getMinutes();
    int getSeconds();
    int getMilliseconds();
    int getRegVal(char addr);
    int bcdToDec(int val);
};
