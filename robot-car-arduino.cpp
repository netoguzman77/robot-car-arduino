#include "arduino.h"
#include "robot-car-arduino.h"

Ultrasonido::Ultrasonido() {}

Ultrasonido::Ultrasonido(byte *_pinTrigger, byte *_pinEcho) {
  pinTrigger = _pinTrigger;
  pinEcho = _pinEcho;

  pinMode(*pinTrigger, OUTPUT);
  pinMode(*pinEcho, INPUT);
}

int Ultrasonido::medirCM() {
  digitalWrite(*pinTrigger, 0);
  delayMicroseconds(4);

  digitalWrite(*pinTrigger, 1);
  delayMicroseconds(10);

  digitalWrite(*pinTrigger, 0);

  distancia = pulseIn(*pinEcho, 1) / 56.812;
  distancia = constrain(distancia, 0, 350);

  return (int) distancia;
}