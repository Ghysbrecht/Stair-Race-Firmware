#pragma once

#include "mbed.h"
#include "myTime.h"
#include "RN2483.h"


class Lora
{
    private:
        RN2483* loraDev;
        Serial* serial;

    public:
        Lora(Serial* serial);
        ~Lora();
        void sendTimeAndId(MyTime* time, uint8_t* id);
        void hardwareResetLoRa();
        void sendACK(uint8_t* payload, int length);
};
