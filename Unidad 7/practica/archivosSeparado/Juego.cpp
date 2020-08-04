#include "Juego.h"
#include <iostream>
#include <conio2.h>
#include <climits>
#include "Auto3.h"
using namespace std;

Juego::Juego(){
	
	auto1 = Auto1(4,4,4);
	auto1.setLimit(0,130,0,45);
	auto2 = Auto2(10,14,14);
	auto2.setLimit(0,130,0,45);
	auto3 = Auto3(10,30,30);
	auto3.setLimit(0,130,0,45);
}

int Juego::checkCollision(){
	
	int x1 = auto1.getX();
	int y1 = auto1.getY();

	int x2 = auto2.getX();
	int y2 = auto2.getY();
	
	int x3 = auto3.getX();
	int y3 = auto3.getY();
	
	int ancho = 3;
	int alto = 4;
	
	
	if(x1 > (x2 - ancho) && x1 < (x2 + ancho) && 
	   y1 > (y2 - alto) && y1 < (y2 + alto))
	{return 2;}
	   
	   if(x1 > (x3 - ancho) && x1 < (x3 + ancho) && 
		  y1 > (y3 - alto) && y1 < (y3 + alto))
	   {return 3;}
	   
	   
	   return 0;
}


void Juego::play(){
	
	/**
	aca de debe ir una condicion de corte que finalice el juego
	en un juego con interacciones se suele hacer un while true y corta
	alguna accion en el juego: vida = 0; alguna tecla, etc.
	En este ejemplo el metodo update dira cuando cortar cuando
	el contador llegue a 0 lanzara un false
	**/

	bool flag = true;
	while(flag) {
		
		auto1.update();
		auto2.update();
		auto3.update();
		
		if (checkCollision() == 2){
			auto2.Cambio();
		}
		if (checkCollision() == 3){
			auto3.Colorear();
		}	
		
		}
		
	
	
}

