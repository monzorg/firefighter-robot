// "firmware/Core.h" -*- C++ -*-
/*
**      /\/\   ___  _ __  _______  _ __ __ _
**     /    \ / _ \| '_ \|_  / _ \| '__/ _` |
**    / /\/\ \ (_) | | | |/ / (_) | | | (_| |
**    \/    \/\___/|_| |_/___\___/|_|  \__, |
**                                     |___/
**    Firefighter Robot, firmware based on Arduino Board
**    @repo firefighter-robot
**    @license MIT License
**    @authors "Filipe Laíns" <filipe.lains@gmail.com>
**    @authors "Luís Ferreira" <lsferreira169@gmail.com>
*/

#pragma once

#define DATA_LED_PIN   13 /// D13
#define RGB_PIN        13 /// D13
#define MOTOR_LEFT     7  /// D7 // TODO: Know if it's correct!
#define MOTOR_RIGHT    4  /// D4 // TODO: Know if it's correct!
#define PX_F 0  /// A0 - Front Side
#define PX_L 1  /// A1 - Left Side
#define NUM_RGB_LEDS   2

enum Direction {
    RIGHT,
    LEFT,
    FORWARD,
    BACKWARD
};

void move(const Direction);
void moveSpeed(const int s);
void moveSpeed(const int m, const int s);
