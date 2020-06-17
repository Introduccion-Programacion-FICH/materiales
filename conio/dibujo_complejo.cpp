#include <iostream>
#include <conio2.h>
#include <ctime>
#include <windows.h>

using namespace std;


int main(int argc, char *argv[]) {
	
	int x=10;
	int y=10;
	
	// Para hacer un dibujo se puede tomar un arte Ascii
	// y a partr del mapa de caracteres se hace una matriz: 
	// Ejemplo un auto:
	
	char Matriz[9][3];
	int ancho = 9;
	int alto = 3;
	
	//9x3:
	
	// 		____|~\_
	// 		[4x4_|_|-]
	// 		 (_)   (_)
	
		
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
	
	
	for (int i= 0; i<ancho; i++){
		for (int k= 0; k<alto; k++){
			
		// por ancho y alto	
		// x + i
		// y + k
		// Matriz i k	
		putchxy(x+i,y+k,Matriz[i][k]); 
		}
	}
	
		return 0;
}
