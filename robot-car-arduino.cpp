/*
MICROPROGRAMACION 2020
*/

#include "arduino.h"
#include "robot-car-arduino.h"
/* **************************************
**      CLASE ULTRASONIDO
************************************** */
//Constructor parametrizado
Ultrasonido::Ultrasonido(byte *_pinTrigger, byte *_pinEcho){
    pinTrigger=_pinTrigger;
    pinEcho=_pinEcho;
    pinMode(*pinTrigger, OUTPUT);
    pinMode(*pinEcho, INPUT);
}
Ultrasonido::Ultrasonido(){}


//Efectua la medicion de distancia devuelve cms de distancia hasta 350cm maxi
int Ultrasonido::medirCM(){	
    digitalWrite(*pinTrigger,LOW);
    delayMicroseconds(4);
    digitalWrite(*pinTrigger,HIGH);
    delayMicroseconds(10);
    digitalWrite(*pinTrigger,LOW);
    distancia=pulseIn(*pinEcho,HIGH)/56.5812;
    distancia=constrain(distancia,0,350);
    return (int) distancia;

}


