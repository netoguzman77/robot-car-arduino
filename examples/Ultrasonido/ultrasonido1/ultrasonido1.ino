
#include <robot-car-arduino.h> 
byte pinEcho=9;
byte pinTrigger=10; 

//Ultrasonido sensor1(&pinTrigger, &pinEcho); 
Ultrasonido sensor2; //Se esta invocando en el sensor por defecto

void setup(){
    Serial.begin(9600); 
    sensor2= Ultrasonido(&pinTrigger, &pinEcho); //se invoca al constructor 
}

void loop(){
    //Serial.println(sensor1.medirCM()); //llamando a sensor1 
    Serial.println(sensor2.medirCM()); //llamando al sensor2
    delay(5000);
}