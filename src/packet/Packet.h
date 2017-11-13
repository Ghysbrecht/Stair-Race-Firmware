#pragma once

#include "myTime.h"
#include <string>

class Packet
{
public:
    static uint8_t* build(MyTime* time, uint8_t* id);
};
