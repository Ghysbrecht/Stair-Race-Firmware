#include "Rfid.h"

//Pins for MFRC522 SPI interface
#define SPI_MOSI    PTC5
#define SPI_MISO    PTC7
#define SPI_SCLK    PTC0
#define SPI_CS      PTC9
#define MF_RESET    PTC8

DigitalIn key(PTB10,PullDown);

Rfid::Rfid():RfChip(SPI_MOSI, SPI_MISO, SPI_SCLK, SPI_CS, MF_RESET)
{
     RfChip.PCD_Init();
}

Rfid::~Rfid()
{
}

int Rfid::cardPresent(){
    //return RfChip.PICC_IsNewCardPresent();
    int keystate = key.read();
    return keystate;
}

uint8_t* Rfid::getCardUid(){
    bool state = RfChip.PICC_ReadCardSerial();
    static uint8_t uid[8];
    printf("Card UID: ");
    for (int i = 0; i < 8; i++)
    {
       if(i < RfChip.uid.size){
           printf("%X02", RfChip.uid.uidByte[i]);
           uid[i] = RfChip.uid.uidByte[i];
       }
       else uid[i] = 0x00;
    }
    return uid;
}
