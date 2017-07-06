#pragma once

#include "arduinoConfig.h"

struct Compass {
    Compass();
    Compass(uint8_t);
    uint16_t read();
    uint16_t val;
    unsigned int uread();
    unsigned int uval;
private:
	void I2Cread(uint8_t , uint8_t, uint8_t *);
};
