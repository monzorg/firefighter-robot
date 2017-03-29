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

#pragma once

/// Motors
#define MMRD  4 // Right Direction
#define MMLD  7 // Left Direction
#define MMRP  5 // Right PWM
#define MMLP  6 // Left PWM

/// Proximity Sensors
#define MPXF  0 // Front
#define MPXL  1 // Left
#define MPXR  2 // Right

// RGB LEDs
#define MRGBL  13 // PIN
#define MRGBLN 2 // Number of RGB Leds in the LED strip

#define MCA    0x60 // Compass Address
#define MDL    13 // Data LED
#define MFP    9 // Fan PIN
#define MSS    9600 // Serial Speed
