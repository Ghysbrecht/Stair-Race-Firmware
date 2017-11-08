#pragma once

#include "Time.h"
#include <string>

class Packet
{
public:
    static uint8_t* build(Time* time, unint8_t* id);
};
