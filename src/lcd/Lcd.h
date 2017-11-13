#pragma once

#include "mbed.h"
#include <string>

class Lcd
{
    public:
    Lcd();
    ~Lcd();
    void setWelcomeScreen();
    void displayRfidCode(uint8_t* id);
};
