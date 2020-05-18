#include<robot-car-arduino.h>
Carro carrito;
int detener=3;
int giro=-90;
 
void setup(){
    //configuraciones del carro
    carrito.potenciaMAX=150; //definimos la velocidad con la que se movera el carro

}

void loop(){
    //si la estructura del sensor central es mayor a los cms para detener pues avanzamos
    if(carrito.UltraC.medirCM()>detener){
        //movemos el carrito hacia adelante
        carrito.mover(10,10);
    }else{
        //entonces me detengo
        carrito.mover(0,0);
        delay(100);
        //evaluo para que lado esta despejado con los sensores laterales
        if(carrito.UltraI.medirCM()>carrito.UltraD.medirCM()){
            // si tengo la apertura a la izquierda
            carrito.girar(giro);
            //si no tengo contadores de vuelta
            //carrito.mover(-10,10);
            //delay(1000);
        }else{
            //giro a la derecha
            carrito.girar(-1*giro);
            //si no tengo contadores de vuelta
            //carrito.mover(10,-10);
            //delay(1000);
        }
    }

}