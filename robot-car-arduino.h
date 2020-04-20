/*
  Libreria de RobotCar Karen 
Universidad de El Salvador, Sede Santa Ana
ciclo I-2020  DEFINA LAS SIGUIENTES CLASES
+ inidica miembro publico
- indicam miembro privado
+ miembro : tipodedatos
*/

#ifndef robot-car-arduino_h
#define robot-car-arduino_h
#include "arduino.h"

/*************************    
	Clase Ultrasonido
**************************
- distancia : long
+ pinEcho : byte*
+ pinTrigger: byte*
**************************
+ medirCM() : int
+ Ultrasonido(byte*,byte*)
****************************/
class Ultrasonido{
    private:
	  long distancia;
	public:
	   byte *pinEcho;
	   byte *pinTrigger;

      
       Ultrasonido(byte *_pinTrigger, byte *_pinEcho);
       Ultrasonido();


       int medirCM();
};


#endif