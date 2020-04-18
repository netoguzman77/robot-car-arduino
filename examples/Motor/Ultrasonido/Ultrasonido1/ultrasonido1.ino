#include <robot-car-arduino.h>
byte pinEcho=9;
byte pinTrigger=10;

//Ultrasonido sensor1(&pinTrigger, &pinEcho);//Declaramos y construimos
Ultrasonido sensor2; //Se esta invocando el constructor por defecto

void setup(){
    Serial.begin(9600);
    sensor2= Ultrasonido(&pinTrigger, &pinEcho); //Se invoca al constructor
}

void loop(){
    Serial.println(sensor1.medirCM());//Llamando sensor1
    Serial.println(sensor2.medirCM());//Llamando sensor2
    delay(5000);
}