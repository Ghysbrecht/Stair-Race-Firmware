#pragma once

#include "mbed.h"
#include "Gps.h"

class Time
{
    private:
        int hours, minutes, seconds, milliseconds;

    public:
    Time(Gps* gps);
    Time(int hours, int minutes, int seconds, int milliseconds);
    ~Time();

    int getHours();
    int getMinutes();
    int getSeconds();
    int getMilliseconds();
};
