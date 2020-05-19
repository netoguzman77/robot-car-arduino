#include <robot-car-arduino.h>
Carro carrito;
int detener=3;
int giro=-90;

void setup(){
    //configuracion del Carro
    carrito.potenciaMax=150; //definimos la velocidad que tendrá el carrito
    
}

void loop(){
    if (carrito.UltraC.medirCM()>detener){
        //Movemos el carrito hacia adelante
        carrito.mover(10,10);
    }else {
        //Entonces me detengo
        carrito.mover(0.0);
        delay(100);
        //evaluo para que lado esta despejado con los sensores laterales
        if (carrito.UltraI.medirCM() > carrito.UltraD.medirCM()) {
            //Si tengo abertura a la izquierda
            carrito.girar(giro);
        }else {
            //giro a la derecha
            carrito.girar(-1*giro);
            
        }
        
        
    }
    

    
}