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

volatile unsigned int Carro::contadorI = 0;
volatile unsigned int Carro::contadorD = 0;

Carro::Carro() {
  pinMode(encoderI, INPUT);
  pinMode(encoderD, INPUT);
  pinMode(adelanteI, OUTPUT);
  pinMode(atrasI, OUTPUT);
  pinMode(potenciaI, OUTPUT);
  pinMode(adelanteD, OUTPUT);
  pinMode(atrasD, OUTPUT);
  pinMode(potenciaD, OUTPUT);

  UltraC = Ultrasonido(&sensorTriggerC, &sensorEchoC);
  UltraI = Ultrasonido(&sensorTriggerI, &sensorEchoI);
  UltraD = Ultrasonido(&sensorTriggerD, &sensorEchoD);
  
  attachInterrupt(digitalPinToInterrupt(encoderI), Carro::contarRuedaI, RISING);
  attachInterrupt(digitalPinToInterrupt(encoderD), Carro::contarRuedaD, RISING);

  Carro::contadorI = 0;
  Carro::contadorD = 0;
}

void Carro::contarRuedaI() {
  if (Carro::contadorI < 65000) Carro::contadorI++;
  else Carro::contadorI = 1;
}

void Carro::contarRuedaD() {
  if (Carro::contadorD < 65000) Carro::contadorD++;
  else Carro::contadorD = 1;
}

void Carro::mover(int izquierda, int derecha) {
  izquierda = constrain(izquierda, -10, 10);
  derecha = constrain(derecha, -10, 10);

  digitalWrite(adelanteI, izquierda < 0 ? 0 : (izquierda > 0 ? 1 : 0));
  digitalWrite(atrasI, izquierda < 0 ? 1 : (izquierda > 0 ? 0 : 0));

  digitalWrite(adelanteD, derecha < 0 ? 0 : (derecha > 0 ? 1 : 0));
  digitalWrite(atrasD, derecha < 0 ? 1 : (derecha > 0 ? 0 : 0));

  derecha = abs(derecha);
  izquierda = abs(izquierda);

  izquierda = map(izquierda, 0, 10, 0, potenciaMax);
  derecha = map(derecha, 0, 10, 0, potenciaMax);

  analogWrite(potenciaD, derecha);
  analogWrite(potenciaI, izquierda);
}

void Carro::girar(int grados) {
  float medioGiro = 40;
  int parar = grados * (medioGiro / 180);
  parar = abs(parar);

  mover(0, 0);
  delay(100);

  contadorI = 0;
  contadorD = 0;

  if (grados > 0) {
    mover(10, -10);
  } else if (grados < 0) {
    mover(-10, 10);
  }

  while(contadorI + contadorD < parar) { }

  mover(0, 0);
  delay(100);
}