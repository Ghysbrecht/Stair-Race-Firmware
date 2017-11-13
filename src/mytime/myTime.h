#pragma once

#include "mbed.h"
#include "Gps.h"

class MyTime
{
    private:
        int hours, minutes, seconds, milliseconds;

    public:
    MyTime(Gps* gps);
    MyTime(int hours, int minutes, int seconds, int milliseconds);
    ~MyTime();

    int getHours();
    int getMinutes();
    int getSeconds();
    int getMilliseconds();
};
