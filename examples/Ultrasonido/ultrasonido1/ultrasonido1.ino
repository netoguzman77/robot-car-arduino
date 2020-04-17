
/*
PROBANDO FUNCIONANMIENTO DE LA CLASE ULTRASONIDO
Se usarán dos tecnicas para instanciar objetos de clase ultrasonido
*/

#include <robot-car-arduino.h>
byte pinEcho=9;
byte pinTrigger=10;



//Ultrasonido sensor1(&pinTrigger, &pinEcho); //declaramos y construimos
Ultrasonido sensor2;// Se esta invocando el contructor por defecto

void setup(){
Serial.begin(9600);
sensor2=Ultrasonido(&pinTrigger, &pinEcho);// se invoca al constructor

}



void loop(){
//Serial.println(sensor1.medirCM());//llamado al sensor1
Serial.println(sensor2.medirCM());//llamado al sensor2
delay(5000);
}