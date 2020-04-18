/* 
 PROBANDO EL FUNCIONAMIENTO DE LA CLASE ULTRASONIDO 
 Se usarán dos tecnicas para instanciar objetos de ultrasonido 
 */

#include <robot-car-arduino.h>
byte pinEcho=9;
byte pinTrigger=10;

 // Ultrasonido sensor1(&pinTrigger,&pinEcho);// declaramos y construimos
 Ultrasonido sensor2;// se esta invocando el constructor por defecto

 void setup(){
     Serial.begin(9600);
     sensor2= Ultrasonido(&pinTrigger,&pinEcho);// se invoca el constructor
 } 



 void loop(){
    // serial.println(sensor1.medirCM()); //llamando a sensor1
     Serial.println(sensor2.medirCM()); //llamando a sensor2
     delay(5000);
     
 }