#pragma once

#include "TextLCD.h"
#include "mbed.h"
#include <string>

class Lcd
{
    private:
    TextLCD* lcd;
    PwmOut* backlight;
    
    public:
    Lcd();
    ~Lcd();
    void setWelcomeScreen();
    void displayRfidCode(uint8_t* id);
};
