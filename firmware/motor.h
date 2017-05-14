/**
**   /\/\   ___  _ __  _______  _ __ __ _
**  /    \ / _ \| '_ \|_  / _ \| '__/ _` |
** / /\/\ \ (_) | | | |/ / (_) | | | (_| |
** \/    \/\___/|_| |_/___\___/|_|  \__, |
**                                  |___/
** Firefighter Robot
** Firefighter Robot firmware based on Arduino Board
**
** @repo firefighter-robot
** @license MIT License
** @authors "Filipe Laíns" <filipe.lains@gmail.com>
** @authors "Luís Ferreira" <lsferreira169@gmail.com>
*/

#include "arduinoConfig.h"

#pragma once

enum MDirection {
  LEFT,
  RIGHT
};

class Motor {
public:
    Motor(const byte , const byte , const byte , const byte );
    void forward(const byte = 255);
    void forward(MDirection, const byte = 255);
    void backward(const byte = 255);
    void backward(MDirection, const byte = 255);
    inline byte getSpeed(MDirection) const;
    inline void setSpeed(MDirection, const byte);
    inline void setSpeed(byte , byte );

private:
    const byte ld, rd, l, r;
    byte ls, rs;
};
