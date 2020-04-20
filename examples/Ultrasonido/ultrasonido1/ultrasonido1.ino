
//*********************************
#include <robot-car-arduino.h>
byte pinEcho=9;
byte pinTrigger=10;

//Ultrasonido sensor1(&pinTrigger,&pinEcho);//declaramos y construimos
Ultrasonido sensor2; //se esta invocando al constructor por defecto

void setup(){
    Serial.begin(9600);
    sensor2= Ultrasonido(&pinTrigger , &pinEcho);//se invoca al constructor

}
 void loop(){
     //Serial.println(sensor1.medirCM());//llamado a sensor1
     Serial.println(sensor2.medirCM());//llamado a sensor 2
     delay(5000);
 }