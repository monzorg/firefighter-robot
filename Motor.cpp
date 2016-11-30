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
  @version ALPHA 0.5 23/11/2016
*/

class Motor {
private:
  const int ld, rd, l, r;
  
public:
  Motor(int ld, int rd, int l, int r)
  {
    l ( l );
    r ( r );
    ld ( ld );
    rd ( rd );
    pinMode(ld, OUTPUT);
    pinMode(rd, OUTPUT);
    digitalWrite(rd, HIGH);
    analogWrite(r, 255);
    digitalWrite(ld, HIGH);
    analogWrite(l, 255);
    foward();
  }
  void forward(int speed)
  {
    digitalWrite(rd, HIGH);
    digitalWrite(ld, HIGH);
  }
  void backward(int speed)
  {
    digitalWrite(rd, LOW);
    digitalWrite(ld, LOW);
  }
};
