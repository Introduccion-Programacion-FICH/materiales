#include <iostream>
#include <conio2.h>
#include <ctime>
#include <windows.h>

using namespace std;

class Camioneta{
	
	int x;
	int y;
	char Matriz[9][3];
	char color[9][3]; // matriz de colores
	int ancho;
	int alto;

public:
	Camioneta();
	void dibujar();
	
};


Camioneta::Camioneta(){
	
	x = 5;
	y = 5;
	ancho = 9;
	alto = 3;
	
	//9x3:
	
	// 		____|~\_
	// 		[4x4_|_|-]
	// 		 (_)   (_)
	
	
	color[0][0]=12;  
	color[1][0]=12; 
	color[2][0]=12; 
	color[3][0]=12;
	color[4][0]=7;  
	color[5][0]=7; 
	color[6][0]=7; 
	color[7][0]=12;
	color[8][0]=0;
	
	color[0][1]=12;  
	color[1][1]=9; 
	color[2][1]=9; 
	color[3][1]=9;
	color[4][1]=4;  
	color[5][1]=4; 
	color[6][1]=4; 
	color[7][1]=4;
	color[8][1]=12;
	
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
	
	for (int i= 0; i<ancho; i++){
		for (int k= 0; k<alto; k++){
			textcolor(color[i][k]);	
			putchxy(x+i,y+k,Matriz[i][k]); 
		}
	}
	
}
int main(int argc, char *argv[]) {
	

	Camioneta *camio = new Camioneta();
	camio->dibujar();

	

	
		return 0;
}
