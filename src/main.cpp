#include "mbed.h"
#include "rtos.h"
#include "Gps.h"
#include "Buzzer.h"
#include "Lcd.h"
#include "Lora.h"
#include "Rfid.h"
#include "Time.h"

DigitalOut led1(LED1);

Serial gps_serial(PTC17,PTC16);
Serial pc(USBTX, USBRX);
Gps gps(&gps_serial);
Rfid rfid;
Lora lora;
Lcd lcd;
Buzzer buzzer;

int main() {
    while (true) {
        gps.run();
        if(rfid.cardPresent()){
            pc.printf("Card present!------\n");
            Time time(&gps);
            pc.printf("Time: %i:%i:%i,%i\n", time.getHours(), time.getMinutes(), time.getSeconds(), time.getMilliseconds());
            buzzer.completeSound();
            pc.printf("Sending packet\n")
            lora.sendTimeAndId(time, rfid.getCardUid());
            lcd.displayRfidCode(rfid.getCardUid());
            Thread::wait(500);
        }
    }
}
