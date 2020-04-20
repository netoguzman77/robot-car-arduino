/*
MICROPROGRAMACION 2020
*/

#include "arduino.h"
#include "robot-car-arduino.h"

//Constructor parametrizado
Ultrasonido::Ultrasonido(byte *_pinTrigger, byte *_pinEcho){
    pinTrigger=_pinTrigger;
    pinEcho=_pinEcho;
    pinMode(*pinTrigger, OUTPUT);
    pinMode(*pinEcho, INPUT);
}
Ultrasonido::Ultrasonido(){};

//hace la medición de distancia, devuelve los cmtros de distancia hasta 350 cm maximo
int Ultrasonido::medirCM{
    digitalWrite(*pinTrigger, LOW);
    delayMicroseconds(4);
    digitalWrite(*pinTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(*pinTrigger, LOW);
    distancia=pulseIn(*pinEcho,HIGH)/56.5812;
    distancia=constrain(distancia,0,350)
    return (int) distancia;
}


/* **************************************
**      CLASE ULTRASONIDO
************************************** */









/*  **************************************************************
                  CLASE CARRO
***********************************************************
*/
//inicializando las variables staticas de la CLASE
volatile unsigned int Carro::contaI=0;
volatile unsigned int Carro::contaD=0;

Carro::Carro(){
	//configurando los pinMode del la potencia del carro
    //encoder, adelante, atras, potencia
    


    //instanciando los sensores ultrasonido y refiriendo
    // invoco constructor parametrizado, new devuelve un puntero
    //UltraD->medir(); //para acceder a sus miembros uso -> por ser puntero

    

	//Agregamos este codigo para registrar las interrupciones
    //RISING indica que se disparara la interrupcion cuando el pin cambie de 0 a 1
    attachInterrupt(digitalPinToInterrupt(encoderI), Carro::contarRuedaI,RISING);
    attachInterrupt(digitalPinToInterrupt(encoderD), Carro::contarRuedaD,RISING);
	Carro::contaI=0; //contadores a cero
    Carro::contaD=0;
}

//METODOS QUE SE EJECUTAN CON LA INTERRUPCION
//Son metodos Staticos pero static va en el .H
void Carro::contarRuedaI(){
    if(Carro::contaI<65000)Carro::contaI++; 
    else Carro::contaI=1;    
}
void Carro::contarRuedaD(){
    if(Carro::contaD<65000) Carro::contaD++;
    else Carro::contaD=1;    
}

//metodo para mover el carro + adelante, - atras, potencia abs


    //Gira la cantidad de grados especifica: - a la izquierda, + derecha
	//usa los contadores de vuelta para la precision al girar
	//tu decides si usas dos llantas para girar o solo una
    //Si tienes contadores de rueda los usaras para hacer el giro
    //si no tienes contadores haras un aproximado con delay(tiempo)


