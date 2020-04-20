/*
Este ejemplo realiza un desplazamiento sencillo en el robot
de modo que mueve el robot y lo detiene cuando encuentra un obstaculo, luego gira a la derecha
para evitar el obstaculo y continua su camino.
*/

#include <robot-car-arduino.h>
Carro m1;

void setup(){

}

void loop(){
    if(m1.UltraC->medir()>12){ //se detiene a los 12cm de un obstaculo 
        m1.mover(255,255);
    }else{
        m1.mover(0,0); //se detiene
        delay(200);
        m1.mover(255,-255); //gira a la derecha
        delay(500); //tiempo de giro a la derecha
        m1.mover(0,0); //se detiene nuevamente
        delay(200);
    }

}
