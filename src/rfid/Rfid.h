#pragma once

#include "mbed.h"

class Rfid
{
    private:
        int cardPresent;
        uint8_t uid[8];

    public:
        Rfid();
        ~Rfid();
        int cardPresent();
        uint8_t* getCardUid();

};
