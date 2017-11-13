#pragma once

#include "mbed.h"
#include "myTime.h"
#include "Simple-LoRaWAN.h"


class Lora
{
    private:
        SimpleLoRaWAN::Node* node;

    public:
        Lora();
        ~Lora();
        void sendTimeAndId(MyTime* time, uint8_t* id);
};
