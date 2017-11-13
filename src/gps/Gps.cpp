#include "Gps.h"
#include "mbed.h"

Gps::Gps(Serial* serial) : Adafruit_GPS(serial)
{
    begin(9600);
    wait(1.0);
    sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
    sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
    sendCommand(PGCMD_ANTENNA);
}

Gps::~Gps()
{

}

void Gps::run()
{
    read();
    if ( newNMEAreceived() ) {
        parse(lastNMEA());
        printf("Time: %i:%i:%i.%i", getHours(), getMinutes(), getSeconds(), getMilliseconds());
    }
}

int Gps::getHours(){
    return hour;
}
int Gps::getMinutes(){
    return minute;
}
int Gps::getSeconds(){
    return seconds;
}
int Gps::getMilliseconds(){
    return milliseconds;
}
