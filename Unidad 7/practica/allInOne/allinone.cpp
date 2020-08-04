#include<iostream>
#include <ctime>
#include <cstdlib>
#include <conio2.h>

using namespace std;


/********/
/** Auto 1 **/
/********/


class Auto1 {
protected:
	int x;
	int y;
	// hago matrices lo suficientemente grandes
	int matriz[5][4];
	int color[5][4]; // matriz de colores
	int ancho;
	int alto;
	int pasoX;
	int pasoY;
	int xnueva;
	int ynueva;
	int maxLimitX;
	int maxLimitY;
	int minLimitX;
	int minLimitY;
	
	
	
	clock_t tempo; //variable para ajustar la velocidad de movimiento de la pelotita
	clock_t paso; //variable para ajustar la velocidad de movimiento de la pelotita
	int velocidad;
	
public:
	void dibujar();
	void borrar(); // para dibujar, antes debemor borrar
	Auto1(int v, int x0,int y0);
	void setLimit(int, int,int, int);
	Auto1(){};
	bool update();
	int getX(){return x;}
	int getY(){return y;}
	
	
	
};


/********/
/** Auto 2 **/
/********/

class Auto2 {
protected:
	int x;
	int y;
	// hago matrices lo suficientemente grandes
	int matriz[5][4];
	int color[5][4]; // matriz de colores
	int ancho;
	int alto;
	int pasoX;
	int pasoY;
	int xnueva;
	int ynueva;
	int maxLimitX;
	int maxLimitY;
	int minLimitX;
	int minLimitY;
	bool cambio;
	clock_t tempo; //variable para ajustar la velocidad de movimiento de la pelotita
	clock_t paso; //variable para ajustar la velocidad de movimiento de la pelotita
	int velocidad;
	int colorAuto;
	
	
public:
	void dibujar();
	void borrar(); // para dibujar, antes debemor borrar
	Auto2(int v, int x0,int y0);
	void setLimit(int, int,int, int);
	Auto2(){};
	void Cambio();
	int getX(){return x;}
	int getY(){return y;}
	void update();
	
	
	
};


/********/
/** Auto 3 **/
/********/

class Auto3 {
protected:
	int x;
	int y;
	// hago matrices lo suficientemente grandes
	int matriz[5][4];
	int color[5][4]; // matriz de colores
	int ancho;
	int alto;
	int pasoX;
	int pasoY;
	int xnueva;
	int ynueva;
	int maxLimitX;
	int maxLimitY;
	int minLimitX;
	int minLimitY;
	bool cambio;
	clock_t tempo; //variable para ajustar la velocidad de movimiento de la pelotita
	clock_t paso; //variable para ajustar la velocidad de movimiento de la pelotita
	int velocidad;
	int colorAuto;
	
	
public:
	void dibujar();
	void borrar(); // para dibujar, antes debemor borrar
	Auto3(int v, int x0,int y0);
	void setLimit(int, int,int, int);
	Auto3(){};
	void Colorear();
	int getX(){return x;}
	int getY(){return y;}
	void update();
	
};


/********/
/** Clase Juego **/
/********/

class Juego{
	
	int teclas[4];
	Auto1 auto1;
	Auto2 auto2;
	Auto3 auto3;
	int checkCollision();
	
	
public:
	Juego();
	void play();
	
};


/********/
/** Auto 1 **/
/********/

Auto1::Auto1(int vel, int x0, int y0){
	
	
	
	velocidad = vel;
	paso=CLOCKS_PER_SEC/velocidad; //cada cuanto se permite mover la pelotita 16 veces por segundo
	tempo=clock(); //inicializamos tempo con el reloj
	
	
	
	int Color = (rand()%15)+1;
	
	
	matriz[0][0]=0;  color[0][0] = 8;
	matriz[0][1]=219; color[0][1] = 15;
	matriz[0][2]=0; color[0][2] = 8;
	matriz[0][3]=219; color[0][3] = 15;
	matriz[1][0]=0;  color[1][0] = Color;
	matriz[1][1]=61; color[1][1] = 8;
	matriz[1][2]=47; color[1][2] = Color;
	matriz[1][3]=61; color[1][3] = 8;
	matriz[2][0]=30; color[2][0] = Color;
	matriz[2][1]=61; color[2][1] = 8;
	matriz[2][2]=0;  color[2][2] = Color;
	matriz[2][3]=61; color[2][3] = 8;
	matriz[3][0]=0;  color[3][0] = Color;
	matriz[3][1]=61; color[3][1] = 8;
	matriz[3][2]=92; color[3][2] = Color;
	matriz[3][3]=61; color[3][3] = 8;
	matriz[4][0]=0;  color[4][0] = 8;
	matriz[4][1]=219; color[4][1] = 15;
	matriz[4][2]=0; color[4][2] = 8;
	matriz[4][3]=219; color[4][3] = 15;
	
	ancho = 5;
	alto = 4;
	pasoX = 3;
	pasoY = 3;
	x = x0;
	y = y0;
	xnueva = x0;
	ynueva = y0;
	
	
	dibujar();
	
}

/*
METODO DIBUJAR
*/

void Auto1::dibujar(){
	
	for (int i= 0; i<ancho; i++){
		for (int k= 0; k<alto; k++){
			textcolor(color[i][k]);
			gotoxy(x+i,y+k);
			cout<<(char) matriz[i][k];
		}
	}
}

/*
METODO BORRAR
*/

void Auto1::borrar(){
	
	for (int i= 0; i<ancho+1; i++){
		for (int k= 0; k<alto+1; k++){
			textcolor(color[i][k]);	
			gotoxy(x+i,y+k);
			cout<<" ";
		}
	}
}


/// El metodo update lo tiene cada objeto pero es 
//// distinto en cada caso, por lo que se debe implementar 
/// en cada clase
bool Auto1::update(){
	
	if (_kbhit()){
		int tecla = getch();
		bool moves = false;
		switch(tecla){
		case (65): { // arriba
			if (y - alto > minLimitY ){borrar(); y = y - pasoY; moves = true;} break;
		}
		case (66):{ // abajo
			if (y < maxLimitY){borrar(); y = y + pasoY; moves = true;} break;
		}
		case (67):{ // derecha
			if (x + ancho < maxLimitX){borrar(); x = x + pasoX; moves = true;} break;
		}
		case (68):{ // izquierda
			if (x - ancho > minLimitX){borrar(); x = x - pasoX; moves = true;} break;
		}
		}
		
		if(moves) {
			dibujar();
		}
	}	
	
}

void Auto1::setLimit(int x0, int x1,int y0, int y1){
	maxLimitX = x1;
	maxLimitY = y1;
	minLimitX = x0;
	minLimitY = y0;
	
}


/********/
/** Auto 2 **/
/********/

Auto2::Auto2(int vel, int x0, int y0){
	
	
	
	velocidad = vel;
	paso=CLOCKS_PER_SEC/velocidad; //fps
	tempo=clock(); //inicializamos tempo con el reloj
	cambio = true;
	colorAuto = 10;
	
	
	matriz[0][0]=0;  color[0][0] = 8;
	matriz[0][1]=219; color[0][1] = 15;
	matriz[0][2]=0; color[0][2] = 8;
	matriz[0][3]=219; color[0][3] = 15;
	matriz[1][0]=0;  color[1][0] = colorAuto;
	matriz[1][1]=61; color[1][1] = 8;
	matriz[1][2]=47; color[1][2] = colorAuto;
	matriz[1][3]=61; color[1][3] = 8;
	matriz[2][0]=30; color[2][0] = colorAuto;
	matriz[2][1]=61; color[2][1] = 8;
	matriz[2][2]=0;  color[2][2] = colorAuto;
	matriz[2][3]=61; color[2][3] = 8;
	matriz[3][0]=0;  color[3][0] = colorAuto;
	matriz[3][1]=61; color[3][1] = 8;
	matriz[3][2]=92; color[3][2] = colorAuto;
	matriz[3][3]=61; color[3][3] = 8;
	matriz[4][0]=0;  color[4][0] = 8;
	matriz[4][1]=219; color[4][1] = 15;
	matriz[4][2]=0; color[4][2] = 8;
	matriz[4][3]=219; color[4][3] = 15;
	
	
	ancho = 5;
	alto = 4;
	pasoX = 3;
	pasoY = 3;
	x = x0;
	y = y0;
	xnueva = x0;
	ynueva = y0;
	
	
	dibujar();
	
}

/*
METODO DIBUJAR
*/

void Auto2::dibujar(){
	
	for (int i= 0; i<ancho; i++){
		for (int k= 0; k<alto; k++){
			textcolor(color[i][k]);
			gotoxy(x+i,y+k);
			cout<<(char) matriz[i][k];
		}
	}
}

/*
METODO BORRAR
*/

void Auto2::borrar(){
	
	for (int i= 0; i<ancho+1; i++){
		for (int k= 0; k<alto+1; k++){
			textcolor(color[i][k]);	
			gotoxy(x+i,y+k);
			cout<<" ";
		}
	}
}


/// El metodo update lo tiene cada objeto pero es 
//// distinto en cada caso, por lo que se debe implementar 
/// en cada clase
void Auto2::Cambio(){
	
	if (cambio){
		matriz[4][0]=219;  color[4][0] = 15;
		matriz[4][1]=0; color[4][1] = 8;
		matriz[4][2]=219; color[4][2] = 15;
		matriz[4][3]=0; color[4][3] = 8;
		
		matriz[3][0]=61;  color[1][0] = 8;
		matriz[3][1]=47; color[1][1] = colorAuto;
		matriz[3][2]=61; color[1][2] = 8;
		matriz[3][3]=0; color[1][3] = 8;
		
		matriz[2][0]=61; color[2][0] = 8;
		matriz[2][1]=0; color[2][1] = colorAuto;
		matriz[2][2]=61;  color[2][2] = 8;
		matriz[2][3]=31; color[2][3] = colorAuto;
		
		matriz[1][0]=61;  color[3][0] = 8;
		matriz[1][1]=92; color[3][1] = colorAuto;
		matriz[1][2]=61; color[3][2] = 8;
		matriz[1][3]=0; color[3][3] = 8;
		
		matriz[0][0]=219;  color[0][0] = 15;
		matriz[0][1]=0; color[0][1] = 8;
		matriz[0][2]=219; color[0][2] = 15;
		matriz[0][3]=0; color[0][3] = 8;
	}
	else {
		matriz[0][0]=0;  color[0][0] = 8;
		matriz[0][1]=219; color[0][1] = 15;
		matriz[0][2]=0; color[0][2] = 8;
		matriz[0][3]=219; color[0][3] = 15;
		matriz[1][0]=0;  color[1][0] = colorAuto;
		matriz[1][1]=61; color[1][1] = 8;
		matriz[1][2]=47; color[1][2] = colorAuto;
		matriz[1][3]=61; color[1][3] = 8;
		matriz[2][0]=30; color[2][0] = colorAuto;
		matriz[2][1]=61; color[2][1] = 8;
		matriz[2][2]=0;  color[2][2] = colorAuto;
		matriz[2][3]=61; color[2][3] = 8;
		matriz[3][0]=0;  color[3][0] = colorAuto;
		matriz[3][1]=61; color[3][1] = 8;
		matriz[3][2]=92; color[3][2] = colorAuto;
		matriz[3][3]=61; color[3][3] = 8;
		matriz[4][0]=0;  color[4][0] = 8;
		matriz[4][1]=219; color[4][1] = 15;
		matriz[4][2]=0; color[4][2] = 8;
		matriz[4][3]=219; color[4][3] = 15;
		
	}
	
	cambio = !cambio;
	
}

void Auto2::update(){
	
	if(tempo+paso<clock()){
		dibujar();
		tempo=clock(); // tomamos el tiempo para saber la proxima vez que movemos la pelotita
	}
}

void Auto2::setLimit(int x0, int x1,int y0, int y1){
	maxLimitX = x1;
	maxLimitY = y1;
	minLimitX = x0;
	minLimitY = y0;
	
}


/********/
/** Auto 3 **/
/********/




Auto3::Auto3(int vel, int x0, int y0){
	
	
	
	velocidad = vel;
	paso=CLOCKS_PER_SEC/velocidad; //fps
	tempo=clock(); //inicializamos tempo con el reloj
	cambio = true;
	colorAuto = (rand()%15)+1;
	
	
	
	matriz[0][0]=0;  color[0][0] = 8;
	matriz[0][1]=219; color[0][1] = 15;
	matriz[0][2]=0; color[0][2] = 8;
	matriz[0][3]=219; color[0][3] = 15;
	matriz[1][0]=0;  color[1][0] = colorAuto;
	matriz[1][1]=61; color[1][1] = 8;
	matriz[1][2]=47; color[1][2] = colorAuto;
	matriz[1][3]=61; color[1][3] = 8;
	matriz[2][0]=30; color[2][0] = colorAuto;
	matriz[2][1]=61; color[2][1] = 8;
	matriz[2][2]=0;  color[2][2] = colorAuto;
	matriz[2][3]=61; color[2][3] = 8;
	matriz[3][0]=0;  color[3][0] = colorAuto;
	matriz[3][1]=61; color[3][1] = 8;
	matriz[3][2]=92; color[3][2] = colorAuto;
	matriz[3][3]=61; color[3][3] = 8;
	matriz[4][0]=0;  color[4][0] = 8;
	matriz[4][1]=219; color[4][1] = 15;
	matriz[4][2]=0; color[4][2] = 8;
	matriz[4][3]=219; color[4][3] = 15;
	
	
	ancho = 5;
	alto = 4;
	pasoX = 3;
	pasoY = 3;
	x = x0;
	y = y0;
	xnueva = x0;
	ynueva = y0;
	
	
	dibujar();
	
}

/*
METODO DIBUJAR
*/

void Auto3::dibujar(){
	
	for (int i= 0; i<ancho; i++){
		for (int k= 0; k<alto; k++){
			textcolor(color[i][k]);
			gotoxy(x+i,y+k);
			cout<<(char) matriz[i][k];
		}
	}
}

/*
METODO BORRAR
*/

void Auto3::borrar(){
	
	for (int i= 0; i<ancho+1; i++){
		for (int k= 0; k<alto+1; k++){
			textcolor(color[i][k]);	
			gotoxy(x+i,y+k);
			cout<<" ";
		}
	}
}


/// El metodo update lo tiene cada objeto pero es 
//// distinto en cada caso, por lo que se debe implementar 
/// en cada clase
void Auto3::Colorear(){
	
	colorAuto = (rand()%15)+1;
	
	color[1][0] = colorAuto;
	color[1][2] = colorAuto;
	color[2][0] = colorAuto;
	color[2][2] = colorAuto;
	color[3][0] = colorAuto;
	color[3][2] = colorAuto;
	
}

void Auto3::update(){
	
	if(tempo+paso<clock()){
		dibujar();
		tempo=clock(); // tomamos el tiempo para saber la proxima vez que movemos la pelotita
	}
}

void Auto3::setLimit(int x0, int x1,int y0, int y1){
	maxLimitX = x1;
	maxLimitY = y1;
	minLimitX = x0;
	minLimitY = y0;
	
}


/********/
/** JUEGO **/
/********/


Juego::Juego(){
	
	auto1 = Auto1(4,4,4);
	auto1.setLimit(0,130,0,45);
	auto2 = Auto2(10,14,14);
	auto2.setLimit(0,130,0,45);
	auto3 = Auto3(10,30,10);
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




int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	Juego J;
	J.play();
	
	return 0;
}


