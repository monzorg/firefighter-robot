#include "tpa81.h"
#include "config.h"
#include "arduinoConfig.h"
#include "Wire.h"

TPASensor::TPASensor() {}

byte TPASensor::read(byte reg_val) {
  Wire.beginTransmission(MTSA); // Begin communication with TPA81
  Wire.write(reg_val+1); // Send reg to TPA81
  Wire.endTransmission();
  Wire.requestFrom(MTSA, 1); // Request 1 byte
  //while(Wire.available() < 1); // Wait for byte to arrive
  val[reg_val] = Wire.read(); // Get byte
  return val[reg_val];
}
