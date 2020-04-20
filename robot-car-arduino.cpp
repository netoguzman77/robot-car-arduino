#include "arduino.h"
#include "robot-car-arduino.h"
/* **************************************
**      CLASE ULTRASONIDO
************************************** */
//constructor parametrizado
Ultrasonido::Ultrasonido(byte *_pinTrigger, byte *_pinEcho){
  pinTrigger=_pinTrigger;
  pinEcho=_pinEcho;
  pinMode(*pinTrigger, OUTPUT);
  pinMode(*pinEcho, INPUT);
}
Ultrasonido::Ultrasonido(){}

int Ultrasonido::medirCM(){
    digitalWrite(*pinTrigger,LOW);
    delayMicroseconds(4);
    digitalWrite(*pinTrigger,HIGH);
    delayMicroseconds(4);
    digitalWrite(*pinTrigger,LOW);
    distancia=pulseIn(*pinEcho,HIGH)/56.5812;
    distancia=constrain(distancia,0,350);
    return (int) distancia;


}