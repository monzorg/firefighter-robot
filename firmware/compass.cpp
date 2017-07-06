#include "compass.h"
#include "config.h"
#include "Wire.h"

Compass::Compass() {}

Compass::Compass(uint8_t adr) {
    Wire.beginTransmission(adr);
    Wire.write(0x37);
    Wire.write(0x02);
    Wire.endTransmission();
}

void Compass::I2Cread(uint8_t reg, uint8_t nb, uint8_t *data) {
  Wire.beginTransmission(MCA);
  Wire.write(reg);
  Wire.endTransmission();

  Wire.requestFrom((byte)MCA, nb);
  uint8_t i;
  while(Wire.available())
    data[i++]=Wire.read();
}

uint16_t Compass::read() {

    Serial.println("Testing...");
    Wire.beginTransmission(MCA);
    Wire.write(0x0A);
    Wire.write(0x01);
    Wire.endTransmission();

    Serial.print("Reading...");
    uint8_t ST1;
    do {
      I2Cread(0x02, 1, &ST1);
      Serial.print(".");
    }
    while(!(ST1&0x01));
    Serial.println(".");

    uint8_t mag[7];
    I2Cread(0x03,7,mag);

    double mx=-(mag[3]<<8 | mag[2]); //+200
    double my=-(mag[1]<<8 | mag[0]); //-70
    double mz=-(mag[5]<<8 | mag[4]); // -700
    val= atan2(my,mx);
    return NULL;
}

unsigned int Compass::uread() {
    //send register 2 to read the angle
    Wire.beginTransmission(MUCA);
    Wire.write(2);
    Wire.endTransmission();

    //request the high and low byte from register 2
    Wire.requestFrom(MCA, 2);
    while(Wire.available() < 2);
    byte highB = Wire.read();
    byte lowB = Wire.read();
    uval = ((highB<<8) + lowB)/10;
    return uval;
}
