#pragma once

#include "arduinoConfig.h"

struct Compass {
  Compass();
	int16_t* read();
  int16_t val[3];
private:
	void I2Cread(uint8_t , uint8_t, uint8_t *);
};
