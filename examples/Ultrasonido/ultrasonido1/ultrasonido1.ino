#include <robot-car-arduino.h>
byte pinEcho=9;
byte pinTrigger=10;

Ultrasonido sensor1(&pinTrigger,&pinEcho);
Ultrasonido sensor2();
void setup()
{
    Serial.begin(9600);
    sensor2= Ultrasonido(&pinTrigger,&pinEcho);   
}
void loop()
{
    Serial.println(sensor2.MedirCM());
    delay(50000);
}
