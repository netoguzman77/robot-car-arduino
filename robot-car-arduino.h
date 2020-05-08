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

class Carro(
  public:
    byte encoderI       = 2;
    byte encoderD       = 3;
    byte adelanteI      = 4;
    byte atrasI         = 5;
    byte potenciaI      = 6;
    byte adelanteD      = 7;
    byte atrasD         = 8;
    byte potenciaD      = 9;
    byte sensorTriggerC = 10;
    byte sensorEchoC    = 11;
    byte sensorTriggerI = 12;
    byte sensorEchoI    = 13;
    byte sensorTriggerD = 14;
    byte sensorEchoD    = 15;
    byte potenciaMax    = 200;

    Ultrasonido UltraC;
    Ultrasonido UltraI;
    Ultrasonido UltraD; 

    static volatile unsigned int contadorI;
    static volatile unsigned int contadorD;

    static void contarRuedaI();
    static void contarRuedaD();

    Carro();

    void mover(int Izquierda, int Derecha);
    void girar(int grados);
)

#endif