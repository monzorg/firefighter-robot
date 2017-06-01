#pragma once

/*
GP2YA41SK0F ( <=> GP2D120 )
Model: "430" [4cm to 30cm]

Based on the SHARP datasheet we can calculate the function (For distance > 3cm) :
Distance = 12.08 X POW(Volt , -1.058)
*/

extern bool repeat;

class PX {
public:
    PX(const int, const int, const int);
    void read();
    int Left, Right, Front;
private:
    const int l, r, f;
    //int read_correction();
};
