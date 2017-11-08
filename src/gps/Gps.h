#pragma once

#include "mbed.h"
#include "MBed_Adafruit_GPS.h"

class Gps : public Adafruit_GPS
{
    public:
    Gps(Serial* serial);
    ~Gps();
    void run();

    int getHours();
    int getMinutes();
    int getSeconds();
    int getMilliseconds();
};
