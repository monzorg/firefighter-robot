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

#include "motor.h"

/* @brief Motor construct
** @param ld  Left Direction PIN
** @param rd  Right Direction PIN
** @param l   Left PWM PIN
** @param r   Right PWM PIN
*/
Motor::Motor(byte ld, byte rd, byte l, byte r) :
  ld(ld), rd(rd), l(l), r(r)
{
  pinMode(ld, OUTPUT);
  pinMode(rd, OUTPUT);
}

/* @brief This function move the motors
** forward.
** @param s Speed of motors
*/
void Motor::forward(byte s)
{
  digitalWrite(rd, LOW);
  digitalWrite(ld, LOW);
  analogWrite(r, s);
  analogWrite(l, s);
}

/* @brief This function move a motor forward
** @param d Direction (Motor Side)
** @param s Speed of the motor
*/
void Motor::forward(MDirection d, byte s)
{
  switch(d)
  {
    case LEFT:
      digitalWrite(ld, LOW);
      analogWrite(l, s);
      break;
    case RIGHT:
      digitalWrite(rd, LOW);
      analogWrite(r, s);
      break;
  }
}

/* @brief This function move the motors
** backward.
** @param s Speed of motors
*/
void Motor::backward(byte s)
{
  digitalWrite(rd, HIGH);
  digitalWrite(ld, HIGH);
  analogWrite(r, s);
  analogWrite(l, s);
}


/* @brief This function move a motor forward
** @param d Direction (Motor Side)
** @param s Speed of the motor
*/
void Motor::backward(MDirection d, byte s)
{
  switch(d)
  {
    case LEFT:
      digitalWrite(ld, HIGH);
      analogWrite(l, s);
      break;
    case RIGHT:
      digitalWrite(rd, HIGH);
      analogWrite(r, s);
      break;
  }
}

byte Motor::getSpeed(MDirection d) const {
  switch(d)
  {
    case LEFT:
      return ls;
      break;
    case RIGHT:
      return rs;
      break;
  }
}

inline void Motor::setSpeed(MDirection d, byte s){
  
}

inline void Motor::setSpeed(byte ls, byte rs)
{
  this->ls = ls;
  this->rs = rs;
}

