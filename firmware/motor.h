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
#include "global.h"

#pragma once

class Motor {
public:
    Motor(const byte , const byte , const byte , const byte );
    void forward(const byte = 255);
    void forward(Direction, const byte = 255);
    void backward(const byte = 255);
    void backward(Direction, const byte = 255);
    void rrotate(Direction , double = 1, const byte = 255);
    inline byte getSpeed(Direction) const;
    inline void setSpeed(Direction, const byte);
    inline void setSpeed(byte , byte );

private:
    const byte ld, rd, l, r;
    byte ls, rs;
};
