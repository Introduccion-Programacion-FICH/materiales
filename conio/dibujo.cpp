#include <iostream>
#include <conio2.h>
#include <ctime>
#include <windows.h>

using namespace std;


int main(int argc, char *argv[]) {
	

	
	// La funcion que nos permite dibujar es
	// putchxy, esta funcion toma 3 parametros
	// posicion x de la pantalla
	// posicion y de la pantalla
	// caracter a mostrar
	
	int x=60;
	int y=30;
	
	putchxy(x,y,'B'); 
	
	// Tambien se puede dar color con la funcion
	// Los colores son 16, y son estos:
	//https://code-reference.com/c/conio.h/textcolor
	
	for (int i= 0; i<16; i++){
		textcolor(i);
		putchxy(10,10+i,'a'); 
		
	}
	
		return 0;
}
