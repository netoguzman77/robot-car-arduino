/*
En este ejemplo se va a verificar el conteo de las vueltas
por parte de los contadores de vueltas o encoder 
en la consola serial se mostrara los contadores de cada vuelta
Intente calcular los valores para girar adecuadamente

Los contadores de vuelta son propiedades Staticas y se acceden asi
Carro::contaI
Carro::contaD
*/
#include <robot-car-arduino.h>
Carro m1;
unsigned int antiguoI, antiguoD;

void setup() {
  // no se necesita codigo porque el constructor de la clase configura todo
    Serial.begin(9600);
    antiguoI=Carro::contaI;
    antiguoD=Carro::contaD;
}

void loop() {
    if(antiguoI!=Carro::contaI || antiguoD!=Carro::contaD){
      Serial.print(Carro::contaI);
      Serial.print("    ---------    ");
      Serial.println(Carro::contaD);
      antiguoI=Carro::contaI;
      antiguoD=Carro::contaD;
    }

}