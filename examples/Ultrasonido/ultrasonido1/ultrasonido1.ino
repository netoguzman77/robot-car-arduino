
#include <robot-car-arduino.h>
byte pinEcho=9;
byte pinTrigger=10;



//Ultrasonido sensor1(&pinTrigger, &pinEcho); //declaramos y construimos
Ultrasonido sensor2;// Se esta invocando el contructor por defecto

void setup(){
Serial.begin(9600);
sensor2=Ultrasonido(&pinTrigger, &pinEcho);// se invoca al constructor

}
