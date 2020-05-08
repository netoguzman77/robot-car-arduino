/*
    PROBANDO EL FUNCIONAMIENTO DE LA CLASE ULTRASONIDO
    Se usarán dos tecnicas para instanciar objetos de ULTRASONIDO
*/

#include <robot-car-arduino.h>
byte pinEcho=9;
byte pinTrigger=10;

//Ultrasonido sensor1(&pinTrigger, &pinEcho) // declareamos y construimos
Ultrasonido sensor2; // invoca al construcctor por defeto

void setup(){
    Serial.begin(9600);
    sensor2=Ultrasonido(&pinTrigger, &pinEcho); // invoca al construcctor

}

void loop(){
    //Serial.println(sensor1.medirCM()); // llamado al sensor1
    Serial.println(sensor2.medirCM); //llamado al sensor2
    delay(5000);
}