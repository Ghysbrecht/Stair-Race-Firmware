#include "Lcd.h"
#include "mbed.h"

Lcd::Lcd()
{
    backlight = new PwmOut(PTB19);
    backlight->period(0.001f);
    backlight->write(0.75f);
    lcd = new TextLCD(PTC5, PTC7, PTC0, PTC9, PTC8, PTC1, TextLCD::LCD20x4);
}

Lcd::~Lcd()
{

}

void Lcd::setWelcomeScreen(){
    lcd->cls();
    lcd->locate(5, 1);
    lcd->printf("StairRace");
    lcd->locate(3, 3);
    lcd->printf("Alpha Version!");
}

void Lcd::displayRfidCode(uint8_t* id){
    lcd->cls();
    lcd->printf("Card UID:");
    lcd->locate(0, 1);
    for(int i=0; i<8; i++){
        lcd->printf("%02X", id[i]);
    }
}
