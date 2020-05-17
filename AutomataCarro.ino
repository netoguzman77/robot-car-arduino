#include <robot-car-arduino.h>
Carro carrito;
int detener=3;
int giro=90;

void setup(){
    //  configuraciones del carro
    //definimos la velocidad con la que se movera el carro
    carrito.potenciaMAX=150;


}
void loop(){
    //si la lectura del sensor central es mayor a los cms para detener pues avanzamos
    if(carrito.UltraC.medirCM() > detener){
        carrito.mover(10,10);
    }else
    {
        //entonces me detengo
        carrito.mover(0,0);  
        delay(100);
        //evaluo para que lado esta despejado con los sensores laterales
        if (carrito.UltraI.medirCM() > carrito.UltraD.medirCM() )
        {
            //si tengo abertura a la izquierda
            carrito.girar(giro);

        }else
        {
            carrito.girar(-1*giro);
        }
        
        

    }
    
}