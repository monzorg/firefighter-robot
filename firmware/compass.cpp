#include "compass.h"
#include "config.h"
#include "Wire.h"

Compass::Compass() {}

void Compass::I2Cread(uint8_t reg, uint8_t nb, uint8_t *data) {
  Wire.beginTransmission(MCA);
  Wire.write(reg);
  Wire.endTransmission();

  Wire.requestFrom((byte)MCA, nb);
  uint8_t i;
  while(Wire.available())
    data[i++]=Wire.read();
}

int16_t* Compass::read() {
    //send register 2 to read the angle
    Wire.beginTransmission(MCA);
    Wire.write(0x0A);
    Wire.write(0x01);
    Wire.endTransmission();

    uint8_t ST1;
    do {
      I2Cread(0x02, 1, &ST1);
    }
    while(!(ST1&0x01));

		uint8_t mag[7];
    I2Cread(0x03,7,mag);

		val[0]=-(mag[3]<<8 | mag[2]); //+200
    val[1]=-(mag[1]<<8 | mag[0]); //-70
    val[2]=-(mag[5]<<8 | mag[4]); // -700
    return val;
}
