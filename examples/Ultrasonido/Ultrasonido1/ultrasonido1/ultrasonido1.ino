/*
    PROBANDO EL FUNCIONAMIENTO DE LA CLASE ULTRASONIDO
    2 tecnicas para instanciar
*/

#include <robot-car-arduino.h>
byte pinEcho = 9;
byte pinTrigger = 10;

//declaramos y construimos
//Ultrasonido sensor1(&pinTrigger, &pinEcho);
//se esta invocando al constructor por defecto
Ultrasonido sensor2;

void setup()
{
    Serial.begin(9600);
    //se invoca al constructor
    sensor2 = Ultrasonido(&pinTrigger, &pinEcho);
}

void loop()
{
    //llamado a sensor1
    //Serial.println(sensor1.medirCM());

    //llamado a sensor 2
    Serial.println(sensor2.medirCM());
    delay(5000);
}