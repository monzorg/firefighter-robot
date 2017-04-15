#pragma once

#include <Thread.h>
#include <FastLED.h>

#include "motor.h"
#include "compass.h"

CRGB rgb_strip[MRGBLN];
Thread* LEDThread = new Thread();
Motor m(MMLD, MMRD, MMLP, MMRP);
Compass c;
