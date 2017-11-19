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
    }
}

void Gps::debug(){
    printf("-------------------------------------------------------\n");
    printf("Time: %d:%d:%d.%u\n", hour, minute, seconds, milliseconds);
    printf("Date: %d/%d/20%d\n", day, month, year);
    printf("Fix: %d\n", (int) fix);
    printf("Quality: %d\n", (int) fixquality);
    if (fix) {
        printf("Location: %5.6f%c, %5.6f%c\n", latitude, lat, longitude, lon);
        printf("HDOP: %5.2f\n", HDOP);
        printf("Speed: %5.2f knots\n", speed);
        printf("Angle: %5.2f\n", angle);
        printf("Altitude: %5.2f\n", altitude);
        printf("Satellites: %d\n", satellites);
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
