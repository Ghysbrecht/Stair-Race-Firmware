#include "mbed.h"
#include "rtos.h"
#include "Gps.h"
#include "Buzzer.h"
#include "Lcd.h"
#include "Lora.h"
#include "Rfid.h"
#include "myTime.h"
#include "DsRTC.h"

DigitalOut led1(LED1);

Serial gps_serial(PTC17,PTC16);
Serial pc(USBTX, USBRX);
Gps gps(&gps_serial);
Rfid rfid;
Lora lora;
Lcd lcd;
Buzzer buzzer;
DsRTC dsRtc;

Thread gps_thread;

void show_gps_info()
{
  while(true){
    //gps.debug();
    Thread::wait(2000);
  }
}

void setup(){
    pc.printf("Starting Stair Race...\n");
    lcd.setWelcomeScreen();
    gps_thread.start(show_gps_info);
}

int main() {
    setup();
    while (true) {
        gps.run();
        if(rfid.cardPresent()){
            pc.printf("Card present!------\n");
            MyTime time(&dsRtc);
            pc.printf("Time: %i:%i:%i,%i\n", time.getHours(), time.getMinutes(), time.getSeconds(), time.getMilliseconds());
            buzzer.completeSound();
            pc.printf("Sending packet\n");
            lora.sendTimeAndId(&time, rfid.getCardUid());
            lcd.displayRfidCode(rfid.getCardUid());
            Thread::wait(1000);
        }
    }
}
