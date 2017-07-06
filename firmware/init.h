#pragma once

#include "arduinoConfig.h"
#include "config.h"

//#include <Thread.h>
#include <FastLED.h>
#include <AnalogButtons.h>

#include "motor.h"
#include "compass.h"
#include "px.h"
//#include "IR.h"
#include "AI.h"
#include "tpa81.h"

bool shouldStart = false;
bool remoteDebug = false;
bool Debug = false;

CRGB rgb_strip[MRGBLN];
AI ai;
Motor m(MMLD, MMRD, MMLP, MMRP);
PX px(MPXL, MPXR, MPXF);
Compass* c = new Compass();
//IR ir;
TPASensor ts;

#include "fw_startbtn.h"

AnalogButtons analogButtons(MSB, INPUT);
Button sbtn = Button(0, &StartButtonClick, &StartButtonHold);
