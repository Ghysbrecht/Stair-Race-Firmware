#include "Rfid.h"

//Pins for MFRC522 SPI interface
#define SPI_MOSI    PTD2
#define SPI_MISO    PTD3
#define SPI_SCLK    PTD1
#define SPI_CS      PTD0
#define MF_RESET    PTC4

DigitalIn key(PTB10,PullDown);

Rfid::Rfid():RfChip(SPI_MOSI, SPI_MISO, SPI_SCLK, SPI_CS, MF_RESET)
{
     RfChip.PCD_Init();
}

Rfid::~Rfid()
{
}

int Rfid::cardPresent(){
    return RfChip.PICC_IsNewCardPresent();
    //int keystate = key.read();
    //return keystate;
}

void Rfid::getCardUid(uint8_t *uid){
    bool state = RfChip.PICC_ReadCardSerial();

    for (int i = 0; i < 8; i++)
    {
       if(i < RfChip.uid.size){
           uid[i] = RfChip.uid.uidByte[i];
       }
       else uid[i] = 0x00;
    }
}
