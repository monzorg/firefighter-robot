#include "compass.h"
#include "config.h"
#include "Wire.h"

Compass::Compass() {
    Wire.begin();
}

unsigned int Compass::read() {
    //send register 2 to read the angle
    Wire.beginTransmission(MCA);
    Wire.write(2);
    Wire.endTransmission();

    //request the high and low byte from register 2
    Wire.requestFrom(MCA, 2);
    while(Wire.available() < 2);
    byte highB = Wire.read();
    byte lowB = Wire.read();
    val = ((highB<<8) + lowB)/10;
    return val;
}
