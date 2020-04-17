/*
PROBANDO EL FUNCIONAMIENTO DE LA CLASE ULTRASONIDO
se usaran dos tecnicas para instanciar objetos de ultrasonido
*/

#include <robot-car-arduino.h>
byte pinEcho=9;
byte pinTrigger=10;

//Ultrasonido sensor1(&pinTrigger, &pinEcho);//declaramos y construimos
Ultrasonido sensor2; //Se esta invocando el constructor por defecto

void setup(){
    Serial.begin(9600);
    sensor2= Ultrasonido(&pinTrigger, &pinEcho); //Se invoca el constructor
}



void loop(){
    //Serial.println(Sensor1.medir()); //llamando al sensor 1
    Serial.println(sensor2.medirCM()); //llamado a sensor 2
    delay(5000);
}