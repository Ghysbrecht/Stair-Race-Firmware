#pragma once

#include "mbed.h"
#include "Time.h"
#include "Simple-LoRaWAN.h"

class Lora
{
    private:
        Node* node;

    public:
        Lora();
        ~Lora();
        void sendTimeAndId(Time time, unint8_t* id);
};
