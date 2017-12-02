#include "Packet.h"

using namespace std;

uint8_t* Packet::build(MyTime* time, uint8_t* id)
{
    static uint8_t txBuffer[13];

    //Time
    txBuffer[0] = time->getHours() & 0xFF;
    txBuffer[1] = time->getMinutes() & 0xFF;
    txBuffer[2] = time->getSeconds() & 0xFF;
    txBuffer[3] = time->getMilliseconds() & 0xFF;
    txBuffer[4] = ( time->getMilliseconds() >> 8 ) & 0xFF;

    //Id
    txBuffer[5] = id[0];
    txBuffer[6] = id[1];
    txBuffer[7] = id[2];
    txBuffer[8] = id[3];
    txBuffer[9] = id[4];
    txBuffer[10] = id[5];
    txBuffer[11] = id[6];
    txBuffer[12] = id[7];

    return txBuffer;
}
