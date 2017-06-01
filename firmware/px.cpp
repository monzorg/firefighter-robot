#include "arduinoConfig.h"
#include "px.h"

//bool repeat = true;

PX::PX(int l, int r, int f) :
  l(l), r(r), f(f)
{
  pinMode(l, INPUT);
  pinMode(r, INPUT);
  pinMode(f, INPUT);
}
/*
int * get_samples(int sample_count, int input){
  int a[sample_count];
  for(size_t i = 0; i < sample_count; i++) {
    a[i] = analogRead(l);
  }

  return a;
}

int get_av(int &  a){
  int av = 0;
  for(size_t i = 0; i < sizeof(a); i++) {
    av += a[i];
  }

  return av / sizeof(a);;
}

int * corr_av(int &a, int av){
  int a2[sizeof(a)];
  int count = 0;
  repeat = false;

  for(size_t i = 0; i < sizeof(a); i++) {
    if(a[i] <= av){
      a2[count] = a[i];
      count++;
    } else {
      repeat = true;
    }
  }

  return a2;
}

int read_correction(int sample_count, int input){
  int *a = get_samples(sample_count, input);
  int av = get_av(a);
  while(repeat){
    a = corr_av(a, av);
    av = get_av(a);
  }

  return av;
}
*/

/*int read_correction(int sample_count, int input){
  int a[sample_count];
  int a2[sample_count];
  int av = 0;
  int av2 = 0;
  int count = 0;

  // Fill a with samples
  for(size_t i = 0; i < sample_count; i++) {
    a[i] = analogRead(l);
    av += a[i];
  }
  av = av / sample_count;

  // Fill a2[] with the valid samples
  for(size_t i = 0; i < sample_count; i++) {
    if(a[i] <= av){
      a2[count] = a[i];
      count++;
      av2 += a[i];
    }
  }
  av2 = av2 / count;

  return av2;
}*/

void PX::read() {
    //int la[SC] = multiple_read(SC, l);
    Left = analogRead(l);
    Right = analogRead(r);
    Front = analogRead(f);
}
