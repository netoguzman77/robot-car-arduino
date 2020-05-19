#include <robot-car-arduino.h>

Carro carrito;
int detener = 3;
int giro = 90;

void setup() {
  carrito.potenciaMax = 150;
}

void loop() {
  int potenciaMover = carrito.UltraC.medirCM() > detener ? 10 : 0;
  carrito.mover(potenciaMover, potenciaMover);

  if (carrito.UltraC.medirCM() < detener) {
    carrito.girar(carrito.UltraI.medirCM() > carrito.UltraD.medirCM() ? giro : giro * -1);
  }
}