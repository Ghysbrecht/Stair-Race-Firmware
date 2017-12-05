#include "Lora.h"
#include "settings.h"
#include "packet.h"
#include "RN2483.h"

DigitalInOut loraResetPin(PTB2);

Lora::Lora(Serial* serial)
{
    this->serial = serial;
    hardwareResetLoRa();
    loraDev = new RN2483(D1, D0);
    serial->printf("Network (ABP) Join %s\r\n", (loraDev->initABP(devAddr, appKey, nwksKey, true) ? "Success": "Failed"));
    //printf("Network (ABP) Join %s\r\n", loraDev.joinABP() ? "Success": "Failed");
}

Lora::~Lora()
{
    delete loraDev;
}

void Lora::sendTimeAndId(MyTime* time, uint8_t* id){
    uint8_t* packet = Packet::build(time, id);
    sendACK(packet, 13);
}

void Lora::hardwareResetLoRa() {
    loraResetPin.input();
    Thread::wait(500);
    loraResetPin.output() ;
    loraResetPin = 1;
    Thread::wait(500);
}

void Lora::sendACK(uint8_t* payload, int length){
    switch (loraDev->send(1, payload, length))
        {
        case NoError:
            serial->printf("Successful transmission.\r\n");
            break;
        case NoResponse:
            serial->printf("There was no response from the device.\r\n");
            break;
        case Silent:
            serial->printf("The device was silenced\r\n");
            break;
        case Timedout:
            serial->printf("Connection timed-out. Check your serial connection to the device!\r\n");
            break;
        case PayloadSizeError:
            serial->printf("The size of the payload is greater than allowed. Transmission failed!\r\n");
            break;
        case InternalError:
            serial->printf("Serious Error\r\n.");
            break;
        case Busy:
            serial->printf("The device is busy.\r\n");
            break;
        case NetworkFatalError:
            serial->printf("There is a non-recoverable error with the network connection. You should re-connect.\r\n");
            break;
        case NotConnected:
            serial->printf("The device is not connected to the network. Please connect to the network before attempting to send data.\r\n");
            break;
        default:
            break;
        }
}
