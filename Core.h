/**
     /\/\   ___  _ __  _______  _ __ __ _ 
    /    \ / _ \| '_ \|_  / _ \| '__/ _` |
   / /\/\ \ (_) | | | |/ / (_) | | | (_| |
   \/    \/\___/|_| |_/___\___/|_|  \__, |
                                    |___/ 
  Firefighter Robot
  Core.ino
  Firefighter Robot firmware based on Arduino Board
  
  @repo firefighter-robot
  @license MIT License
  @authors "Filipe Laíns" <filipe.lains@gmail.com>
  @authors "Luís Ferreira" <lsferreira169@gmail.com>
  @version ALPHA 0.5 14/11/2016
*/

#pragma once

#define PX_F 0  // A0 - Front Side
#define PX_L 1  // A1 - Left Side
#define NUM_RGB_LEDS   2

enum Direction {
  RIGHT,
  LEFT,
  FRONT
};
