#include <iostream>
#include <ctime>
#include <conio2.h>
#include <windows.h>

using namespace std;


/*
A parti de la clase general creada para 
Dibujar y manejar el tiempo.
Podemos utilizarla tambien con teclado
En este caso, el update no sería con un
Contador, sino que la posicion la actualiza el teclado
*/


class ObjetoDibuja{
	
protected:
	int x;
	int y;
	// hago matrices lo suficientemente grandes
	char matriz[20][20];
	int color[20][20]; // matriz de colores
	int ancho;
	int alto;
	
	clock_t tempo; //variable para ajustar la velocidad de movimiento de la pelotita
	clock_t paso; //variable para ajustar la velocidad de movimiento de la pelotita
	int velocidad;
	
public:
	ObjetoDibuja( int v);
	void dibujar();
	void borrar(); // para dibujar, antes debemor borrar
};


ObjetoDibuja::ObjetoDibuja(int vel){
	
	
	
	velocidad = vel;
	paso=CLOCKS_PER_SEC/velocidad; //cada cuanto se permite mover la pelotita 16 veces por segundo
	tempo=clock(); //inicializamos tempo con el reloj
	
	
}

void ObjetoDibuja::dibujar(){
	
	
	// antes de dibujar
	for (int i= 0; i<ancho; i++){
		for (int k= 0; k<alto; k++){
			textcolor(color[i][k]);	
			putchxy(x+i,y+k,matriz[i][k]); 
		}
	}
	
}

void ObjetoDibuja::borrar(){
	
	
	// antes de dibujar
	for (int i= -1; i<ancho+1; i++){
		for (int k= -1; k<alto+1; k++){
			putchxy(x+i,y+k,' '); 
		}
	}
	
}




/**
Heredo el objeto dibuja
**/



class Camioneta: public ObjetoDibuja{
	// el offset es la velocidad de salto
	// en la pantalla
	int offsert;
public:
	Camioneta(int x0,int y0,int vel);
	
	//En este caso el update recibe una instruccion
	// 1: izquierda
	// 2 derecha
	// 3 arriba
	// 4 abajo
	bool update(int);
	
	
	
};


Camioneta::Camioneta(int x0, int y0, int vel): ObjetoDibuja(vel){
	
	
	int colorAleatorio = (rand()%15)+1;
	
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
	
	
	
	matriz[0][0]='_';  
	matriz[1][0]='_'; 
	matriz[2][0]='_'; 
	matriz[3][0]='_';
	matriz[4][0]='|';  
	matriz[5][0]='~'; 
	matriz[6][0]='\\'; 
	matriz[7][0]='_';
	matriz[8][0]=' ';
	
	matriz[0][1]='[';  
	matriz[1][1]='4'; 
	matriz[2][1]='x'; 
	matriz[3][1]='4';
	matriz[4][1]='|';  
	matriz[5][1]='_'; 
	matriz[6][1]='|'; 
	matriz[8][1]=']';
	
	matriz[0][2]=' ';  
	matriz[1][2]=' '; 
	matriz[2][2]='('; 
	matriz[3][2]='_';
	matriz[4][2]=')';  
	matriz[5][2]=' '; 
	matriz[6][2]='('; 
	matriz[7][2]='_';
	matriz[8][2]=')';
	
	ancho = 9;
	alto = 3;
	x = x0;
	y = y0;
	offsert = 2;
	
	dibujar();
	
	
}


/// El metodo update lo tiene cada objeto pero es 
//// distinto en cada caso, por lo que se debe implementar 
/// en cada clase
bool Camioneta::update(int v){
	
	
	// primero borro
	borrar();
	
	// mientras no llegue 70
	switch(v){
	case 1: { // izqierda
		x = x - 1*(offsert);
		break;} 
	case 2: { // derecha
		x = x + 1*(offsert);
		break;} 
	case 3: { // arriba
		y = y - 1*(offsert);
		break;} 
	case 4: // abajo
	{
		y = y + 1*(offsert);
		break;} 
	
	}
	
	// ponemos como condicion de corte
	// que no pase la posicion 70 de x
	// ni baje de la posicion 0
		
		if(x < 70 && x > 0){
			
			dibujar();

		return true;
	}
	
	else{return false;};
	
}


class Juego{
	
	
	
	Camioneta *camio1 = new Camioneta(3,5,5); 
	
//	Camioneta *camio2 = new Camioneta(3,15,10); 
	
//	Camioneta *camio3 = new Camioneta(3,25,15); 
	
	
	
	
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
		

		if(kbhit()) { 
			int tecla=getch();
			
			switch(tecla)
			{
			case 75: //izquierda
				flag = camio1->update(1);
				break;
			case 77: //derecha
				flag = camio1->update(2);
				break;
			case 72: //arriba
				flag = camio1->update(3);
				break;
			case 80: //abajo
				flag = camio1->update(4);
				break;
			}
		}
	}
}





int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	Juego J;
	J.play();
	
	return 0;
}
