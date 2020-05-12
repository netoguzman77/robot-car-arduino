/*
  Libreria de RobotCar
Universidad de El Salvador, Sede Santa Ana
ciclo I-2019   DEFINA LAS SIGUIENTES CLASES
+ inidica miembro publico
- indicam miembro privado
+ miembro : tipodedatos
*/

#ifndef robot - car - arduino_h
#define robot -car - arduino_h
#include <Arduino.h>

class Ultrasonido
{
private:
	long distancia;

public:
	byte *pinEcho;
	byte *pinTrigger;
	Ultrasonido(byte *_pinTrigger, byte *_pinEcho);
	Ultrasonido();

	int medirCM();
};

class Carro
{

public:
	byte encoderI = 2;		 //pin del encoder de la llanta izquierda
	byte encoderD = 3;		 // pin del encoder de la llanta derecha
	byte adelanteI = 4;		 // pin avance adelante llanta Izquierda
	byte atrasI = 5;		 // pin de reversa llanta izquierda
	byte potenciaI = 6;		 // pin de potencia llanta Izquierda pin PWM
	byte adelanteD = 7;		 // Adelante llanta Derecha
	byte atrasD = 8;		 // atras llanta Derecha
	byte potenciaD = 9;		 // potencia llanta Derecha pin PWM
	byte sensortrigerC = 10; //Sensor Ultrasonido Central Trigger
	byte sensorechoC = 11;	 //Sensor Ultrasonido Central Echo
	byte sensortrigerI = 12; //Sensor Ultrasonido Izquierda Trigger
	byte sensorechoI = 13;	 //Sensor Ultrasonido Izquierda Echo
	byte sensortrigerD = 14; //Sensor Ultrasonido Derecha Trigger
	byte sensorechoD = 15;	 //Sensor Ultrasonido Derecha Echo
	byte potenciaMAX = 200;	 //limite regulador de la potencia maxima
	Ultrasonido UltraC;		 // Se declara como PUNTEROS
	Ultrasonido UltraI;		 // en el cpp se va a instanciar y a referir
	Ultrasonido UltraD;

	static volatile unsigned int contaI; //contador de las vueltas de la llanta Izquierda
	static volatile unsigned int contaD; //contador de las vueltas de la llanta Derecha

	static void contarRuedaI();
	static void contarRuedaD();

	Carro();

	void mover(int Izquierda, int Derecha);

	void girar(int grados);
};

#endif