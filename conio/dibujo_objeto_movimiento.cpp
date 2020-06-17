#include <iostream>
#include <conio2.h>
#include <ctime>
#include <windows.h>

using namespace std;


/*
A partir del ejemplo del dibujo del Objeto
y el ejemplo del movimiento se puede
hacer un ejemplo con objetos complejos en movimiento
Las caracteristica de los objetos que se dibujan y 
los que se mueven son siempre iguales, por lo que se pueden heredar
*/



class Camioneta{
	
	int x;
	int y;
	char Matriz[9][3];
	char color[9][3]; // matriz de colores
	int ancho;
	int alto;
	int colorAleatorio;
	
	
	clock_t tempo; //variable para ajustar la velocidad de movimiento de la pelotita
	clock_t paso; //variable para ajustar la velocidad de movimiento de la pelotita
	int velocidad;
	
public:
	Camioneta(int,int,int);
	void dibujar();
	bool update();
	void borrar(); // para dibujar, antes debemor borrar
	
};


Camioneta::Camioneta(int vel, int xx, int yy){
	
	
	velocidad = vel;
	paso=CLOCKS_PER_SEC/velocidad; //cada cuanto se permite mover la pelotita 16 veces por segundo
	tempo=clock(); //inicializamos tempo con el reloj
	
	x = xx;
	y = yy;
	ancho = 9;
	alto = 3;
	colorAleatorio = (rand()%15)+1;
	
	//9x3:
	
	// 		____|~\_
	// 		[4x4_|_|-]
	// 		 (_)   (_)
	
	
	color[0][0]=colorAleatorio;  
	color[1][0]=colorAleatorio; 
	color[2][0]=colorAleatorio; 
	color[3][0]=colorAleatorio;
	color[4][0]=7;  
	color[5][0]=7; 
	color[6][0]=7; 
	color[7][0]=colorAleatorio;
	color[8][0]=0;
	
	color[0][1]=colorAleatorio;  
	color[1][1]=9; 
	color[2][1]=9; 
	color[3][1]=9;
	color[4][1]=4;  
	color[5][1]=4; 
	color[6][1]=4; 
	color[7][1]=4;
	color[8][1]=colorAleatorio;
	
	color[0][2]=0;  
	color[1][2]=0; 
	color[2][2]=1; 
	color[3][2]=16;
	color[4][2]=1;  
	color[5][2]=0; 
	color[6][2]=1; 
	color[7][2]=16;
	color[8][2]=1;
	
	
	
	Matriz[0][0]='_';  
	Matriz[1][0]='_'; 
	Matriz[2][0]='_'; 
	Matriz[3][0]='_';
	Matriz[4][0]='|';  
	Matriz[5][0]='~'; 
	Matriz[6][0]='\\'; 
	Matriz[7][0]='_';
	Matriz[8][0]=' ';
	
	Matriz[0][1]='[';  
	Matriz[1][1]='4'; 
	Matriz[2][1]='x'; 
	Matriz[3][1]='4';
	Matriz[4][1]='|';  
	Matriz[5][1]='_'; 
	Matriz[6][1]='|'; 
	Matriz[7][1]='-';
	Matriz[8][1]=']';
	
	Matriz[0][2]=' ';  
	Matriz[1][2]=' '; 
	Matriz[2][2]='('; 
	Matriz[3][2]='_';
	Matriz[4][2]=')';  
	Matriz[5][2]=' '; 
	Matriz[6][2]='('; 
	Matriz[7][2]='_';
	Matriz[8][2]=')';
}


void Camioneta::dibujar(){
	
	
	// antes de dibujar
	for (int i= 0; i<ancho; i++){
		for (int k= 0; k<alto; k++){
			textcolor(color[i][k]);	
			putchxy(x+i,y+k,Matriz[i][k]); 
		}
	}
	
}

void Camioneta::borrar(){
	
	
	// antes de dibujar
	for (int i= 0; i<ancho; i++){
		for (int k= 0; k<alto; k++){
			textcolor(color[i][k]);	
			putchxy(x+i,y+k,' '); 
		}
	}
	
}

bool Camioneta::update(){
	
	
	// mientras no llegue 70
	if (x<90){
		
		if(tempo+paso<clock()){
			
			// borro
			borrar();
			// muevo
			x++;
			// dibujo
			dibujar();
			
			tempo=clock(); // tomamos el tiempo para saber la proxima vez que movemos la pelotita
		}
		return true;
	}
	
	else{return false;};
	
}


class Juego{
	

	
	Camioneta *camio1 = new Camioneta(3,5,5); 
	
	Camioneta *camio2 = new Camioneta(10,5,15); 
	
	Camioneta *camio3 = new Camioneta(7,5,25); 
	

	
	
public:
	Juego(){}
	void play();
	
};

void Juego::play(){
	
	/**
	aca de debe ir una condicion de corte que finalice el juego
	en un juego con interacciones se suele hacer un while true y corta
	alguna accion en el juego: vida = 0; algujna tecla, etc.
	En este ejemplo el metodo update dira cuando cortar cuando
	el contador llegue a 0 lanzara un false
	**/
	
	bool flag = true;
	while(flag) {
		flag = camio1->update();
		// el objeto 1 es el ultimo en terminar
		camio2->update();
		camio3->update();
		
	}
	
}





int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	Juego J;
	J.play();
	
	return 0;
}
