#pragma once

#include "arduinoConfig.h"
#include "config.h"

enum struct IRByte : unsigned char {
    A = 0x00,
    B = 0x00,
    C = 0x00,
    D = 0x00,
    UP = 0x00,
    E = 0x00,
    LEFT = 0x00,
    GEAR = 0x00,
    RIGHT = 0x00,
    N0 = 0x00,
    DOWN = 0x00,
    F = 0x00,
    N1 = 0x00,
    N2 = 0x00,
    N3 = 0x00,
    N4 = 0x00,
    N5 = 0x00,
    N6 = 0x00,
    N7 = 0x00,
    N8 = 0x00,
    N9 = 0x00
};

class IR {
public:
    IR();
    int read(void (*)());
};
