/*
PRUEBA DE LA CLASE ULTRASONIDO
*/
#include <robot-car-arduino.h>
byte pinEcho=9;
byte pinTrigger=10;


Ultrasonido sensor; //declaracion del objeto

void setup(){
    Serial.begin(9600);
    sensor= Ultrasonido(&pinTrigger, &pinEcho); //Se Invoca al constructor p/ configurar valores
}

void loop(){
    
    Serial.println(sensor.medirCM()); //llamado al sensor para imprimir la distancia en centimetros
    delay(5000);
}
