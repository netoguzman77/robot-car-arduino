/*
    PROBANDO EL FUNCIONAMIENTO DE LA CLASE ULTRASONIDO
    Se usara dos tecnicas para instanciar objetos de Ultrasonido
*/

#include <robot-car-arduino.h>
byte pinEcho=9;
byte pinTrigger=10;

Ultrasonido sensor1(&pinTrigger, &pinEcho); //declaramos y contruimos
Ultrasonido sensor2(); //se esta invocando el constructor por defecto

void setup(){

    Serial.begin(9600);
    sensor1 = Ultrasonido(&pinTrigger,&pinEcho);//se invoca al constructor

}

void loop(){
    //Serial.println(sensor1.medirCM());//llamado a sensor1
    Serial.println(sensor1.medirCM());
    delay(5000);
}