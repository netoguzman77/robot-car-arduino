#include <robot-car-arduino.h>
byte pinEcho=9;
byte pinTrigger=10;

Ultrasonido sensor1;

void setup(){
    Serial.begin(9600);
    sensor1 = Ultrasonido(&pinTrigger,&pinEcho);
}

void loop(){
    Serial.println(sensor1.medirCM());
    delay(5000);
}