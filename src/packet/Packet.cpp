#include "Packet.h"

using namespace std;

uint8_t* Packet::build(Time* time, unint8_t* id)
{
    static uint8_t txBuffer[14];

    //Time
    txBuffer[0] = time->getHours & 0xFF;
    txBuffer[1] = time->getMinutes & 0xFF;
    txBuffer[2] = time->getSeconds & 0xFF;
    txBuffer[3] = time->milliseconds & 0xFF;
    txBuffer[4] = ( time->milliseconds >> 8 ) & 0xFF;

    //Id
    txBuffer[6] = id[0];
    txBuffer[7] = id[1];
    txBuffer[8] = id[2];
    txBuffer[9] = id[3];
    txBuffer[10] = id[4];
    txBuffer[11] = id[5];
    txBuffer[12] = id[6];
    txBuffer[13] = id[7];

    return txBuffer;
}
