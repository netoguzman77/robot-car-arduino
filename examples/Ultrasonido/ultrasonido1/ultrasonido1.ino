/*
PRUBA DE LA CLASE ULTRASONIDO
*/
#include <robot-car-arduino.h>
byte pinEcho=9;
byte pinTrigger=10;


Ultrasonido sensor2; //se esta invocando el constructor por defecto, declaracion del objeto

void setup(){
    Serial.begin(9600);
    sensor2= Ultrasonido(&pinTrigger, &pinEcho); //Se Invoca al constructor para la configuracion de los valores
}

void loop(){
    
    Serial.println(sensor2.medirCM()); //llamado a sensor 2 para imprimir la distancia en CM
    delay(5000);
}