#pragma once

#include "arduinoConfig.h"

struct Compass {
    Compass();
    unsigned int read();
    unsigned int val;
};
