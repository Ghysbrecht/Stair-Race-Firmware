#pragma once

#include "mbed.h"
#include "MFRC522.h"

class Rfid
{
    private:
        int _cardPresent;
        MFRC522 RfChip;

    public:
        Rfid();
        ~Rfid();
        int cardPresent();
        void getCardUid(uint8_t *uid);

};
