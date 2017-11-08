#include "Lora.h"
#include "settings.h"
#include "packet"

Lora::Lora()
{
    node = new ABP::Node(devAddr, nwksKey, appKey);
    node->disableLinkCheck();
    node->setSpreadFactor(DR_SF7);
}

Lora::~Lora()
{
    delete node;
}

void sendTimeAndId(Time time, unint8_t* id){
    uint8_t* packet = Packet::build(time, id);
    node->send(packet, 14);
}
