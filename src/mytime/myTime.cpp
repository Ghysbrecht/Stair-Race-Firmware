#include "myTime.h"

MyTime::MyTime(Gps* gps) 
    : MyTime(gps->getHours(), gps->getMinutes(), gps->getSeconds(), gps->getMilliseconds())
{

}

MyTime::MyTime(int hours, int minutes, int seconds, int milliseconds)
{
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    this->milliseconds = milliseconds;
}

MyTime::~MyTime()
{
    
}

int MyTime::getHours(){
    return hours;
}
int MyTime::getMinutes(){
    return minutes;
}
int MyTime::getSeconds(){
    return seconds;
}
int MyTime::getMilliseconds(){
    return milliseconds;
}
