/* Probando el funcionamiento de la clase ultrasonido 
    Se usaran dos tecnicas para instanciar objetos de ultrasonido
*/

#include <robot-car-arduino.h>
byte pinEcho=9;
byte pinTrigger=10;

Ultrasonido sensor2;

void setup(){
    Serial.begin(9600);
    sensor2 = Ultrasonido(&pinTrigger,&pinEcho); //Se invoca el constructor 
}

void loop(){
    Serial.println(sensor2.medirCM());
    delay(5000);
}