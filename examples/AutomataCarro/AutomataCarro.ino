#include <robot-car-arduino.h>
Carro carrito;
int detener = 3;
int giro = 90;

void setup()
{
    carrito.potenciaMAX = 150;
}

void loop()
{
    if (carrito.UltraC.medirCM() > detener)
    {
        //Movimiento hacia adelante
        carrito.mover(10, 10);
    }
    else
    {
        //Detener
        carrito.mover(0, 0);
        delay(100);
        //Identificar  si no hay obstaculos a la izquierda
        if (carrito.UltraI.medirCM() > carrito.UltraD.medirCM())
        { //si no hay obstaculos, gito a la izquierda
            carrito.girar(giro);
            //si no tengo contadores de vueltas: ejecutar codigo comentado
            //carrito.mover(-10,10);
            //dalay(1000);
        }
        else
        {
            //si hay obstaculos, entonces giro a la derecha
            carrito.girar(-1*giro);
             //si no tengo contadores de vueltas: ejecutar codigo comentado
            //carrito.mover(10,-10);
            //dalay(1000);

        }
    }
}