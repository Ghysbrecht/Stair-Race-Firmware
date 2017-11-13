#include "Rfid.h"

Rfid::Rfid()
{
    //Init RFID library
}

Rfid::~Rfid()
{
}

int Rfid::cardPresent(){
    return _cardPresent;
}

uint8_t* Rfid::getCardUid(){
    return uid;
}
