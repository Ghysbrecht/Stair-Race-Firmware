#include "Time.h"

Time::Time(Gps* gps)
{
    this(gps->getHours, gps->getMinutes, gps->getSeconds, gps->getMilliseconds)
}

Time::~Time(int hours, int minutes, int seconds, int milliseconds)
{
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    this->milliseconds = milliseconds;
}

int Time::getHours(){
    return hours;
}
int Time::getMinutes(){
    return minutes;
}
int Time::getSeconds(){
    return seconds;
}
int Time::getMilliseconds(){
    return milliseconds;
}
