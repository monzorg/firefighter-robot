#include "arduinoConfig.h"

#include "px.h"

PX::PX(int l, int r, int f) :
  l(l), r(r), f(f)
{
  pinMode(l, INPUT);
  pinMode(r, INPUT);
  pinMode(f, INPUT);
}

void PX::read() {
    Left = analogRead(l);
    Right = analogRead(r);
    Front = analogRead(f);
}
