#ifndef robot-car-arduino_h
#define robot-car-arduino_h
#include "arduino.h"

class Ultrasonido {
  private: 
    long distancia;
  public:
    byte *pinEcho;
    byte *pinTrigger;
  
  Ultrasonido(byte *_pinTrigger, byte *_pinEcho);
  Ultrasonido();

  int medirCM();
}

#endif