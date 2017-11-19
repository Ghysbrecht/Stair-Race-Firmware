#include "Lora.h"
#include "settings.h"
#include "packet.h"


Lora::Lora()
{
    node = new SimpleLoRaWAN::ABP::Node(devAddr, nwksKey, appKey);
    node->disableLinkCheck();
    node->setSpreadFactor(DR_SF7);
}

Lora::~Lora()
{
    delete node;
}

void Lora::sendTimeAndId(MyTime* time, uint8_t* id){
    uint8_t* packet = Packet::build(time, id);
    node->send(packet, 14,true);
}
