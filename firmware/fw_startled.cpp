#include <FastLED.h>
#include "config.h"

extern CRGB rgb_strip[MRGBLN];
extern bool shouldStart;

#include <AnalogButtons.h>
extern AnalogButtons analogButtons;

void callback_startled() {
    int i;
    int j = 255;
    for(i = 0; i < 255; i++)
    {
        rgb_strip[0] = CRGB(i,0,0);
        rgb_strip[1] = CRGB(j,0,0);
        FastLED.show();
        j--;
        analogButtons.check();
        if(shouldStart)
            return;
    }
    for(int i = 255; i > 0; i--)
    {
        rgb_strip[0] = CRGB(i,0,0);
        rgb_strip[1] = CRGB(j,0,0);
        FastLED.show();
        j++;
        analogButtons.check();
        if(shouldStart)
            return;
    }
}
