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
#define MMRD   4 // Right Direction
#define MMLD   7 // Left Direction
#define MMRP   5 // Right PWM
#define MMLP   6 // Left PWM
#define MMMIN  100

/// Proximity Sensors
#define MPXF   A0 // Front
#define MPXL   A1 // Left
#define MPXR   A2 // Right
#define MPXDM  305 // Direction Max Value
#define MPXHW 136 // Hallway PX Max Value
#define MPXDRD 1000 // Door Rotate Delay
#define MPXFM  475 // Front Max Value
/// PX Error Correction
#define MPXSC     10 // Sample Count
#define MPXMXE    25 // Max Error

/// RGB LEDs
#define MRGBL  13 // PIN
#define MRGBLN 2 // Number of RGB Leds in the LED strip

/// Line Detector
#define MLDL 11 // Line Detector Left
#define MLDR 12 // Line Detector Right
#define MLDI 1	// Line Detector Inverter  <------ /!\

/// Infrared
#define MIRP    2 // IR PIN
#define MIRSB   2200 // Start BIT
#define MIRB1   1600 // BIT1
#define MIRB0   560 // BIT0

#define MMPU9250 0x68 // MPU9250 Address
#define MUCA    0x60 // Compass Address
#define MCA		 0x0C // New Compass Address
#define MTSA   0x68 // TPA81 Thermal Sensor Address
#define MDL    13 // Data LED
#define MFP    9 // Fan PIN
#define MSS    115200 // Serial Speed
#define MSB    7 // Button PIN
#define MLS
