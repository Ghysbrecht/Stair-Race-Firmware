#include "mbed.h"
#include "rtos.h"
#include "Buzzer.h"
#include "Lcd.h"
#include "Lora.h"
#include "Rfid.h"
#include "myTime.h"
#include "DsRTC.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);

Serial pc(USBTX, USBRX);
Rfid rfid;
Lora lora(&pc);
Buzzer buzzer;
DsRTC dsRtc;

Thread gps_thread;

void show_gps_info()
{
  while(true){
    led1 = !led1;
    Thread::wait(500);
  }
}

void setup(){
    led2 = 1;
    pc.baud(9600);
    pc.printf("Starting Stair Race...\n");
    gps_thread.start(show_gps_info);
}

int main() {
    setup();
    while (true) {
        if(rfid.cardPresent()){
            led2 = 0;
            pc.printf("Card present!\n");

            //Get the time
            MyTime time(&dsRtc);
            pc.printf("Time: %i:%i:%i,%i\n", time.getHours(), time.getMinutes(), time.getSeconds(), time.getMilliseconds());

            //Get the UID
            pc.printf("Card UID: ");
            uint8_t uid[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
            rfid.getCardUid(uid);
            for (int i = 0; i < 8; i++) pc.printf("%02x", uid[i]);
            pc.printf("\n");

            //Send the time and UID
            pc.printf("Sending packet\n");
            lora.sendTimeAndId(&time, uid);
            buzzer.completeSound();
            Thread::wait(1000);
            pc.printf("Done!\n");
            led2 = 1;
        }
    }
}
