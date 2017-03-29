/**
**   /\/\   ___  _ __  _______  _ __ __ _
**  /    \ / _ \| '_ \|_  / _ \| '__/ _` |
** / /\/\ \ (_) | | | |/ / (_) | | | (_| |
** \/    \/\___/|_| |_/___\___/|_|  \__, |
**                                    |___/
** Firefighter Robot
** Firefighter Robot firmware based on Arduino Board
**
** @repo firefighter-robot
** @license MIT License
** @authors "Filipe Laíns" <filipe.lains@gmail.com>
** @authors "Luís Ferreira" <lsferreira169@gmail.com>
*/

#include "config.h"
#include "init.h"

/**
     Loop Code
*/
void loop() {
  //m.forward(255);
  Serial.println(c.read());
  delay(1000);
}
