#include "Rfid.h"

Rfid::Rfid()
{
    //Init RFID library
}

Lora::~Lora()
{
}

int cardPresent(){
    return cardPresent;
}

uint8_t* getCardUid(){
    return uid;
}
