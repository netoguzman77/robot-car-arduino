#include <RobotCar.h>
Carro Rcar;


void setup() {
  // no se necesita codigo porque el constructor de la clase configura todo
    Serial.begin(9600);
    Serial.println("*********SENSORES ULTRASONIDO*********");
    Serial.println("IZQ \t CENT \t DER");


}

void loop() {
    //Los sensores ultrasonido estan en propiedades que son punteros
    Serial.print(Rcar.UltraI->medir());
    Serial.print("\t");
    Serial.print(Rcar.UltraC->medir());
    Serial.print("\t");
    Serial.println(Rcar.UltraD->medir());
    delay(500);
    

}