#include <iostream>
#include <ctime>
#include <conio2.h>
#include <windows.h>

using namespace std;


// para dibujar, primero tengo que borrar la posicion actual
// acualizar la coodenada
// y finalmente volver a dibujar

void dibujar(int x, int y){
	
	putchxy(x,y,'x');
	
}

void borrar(int x, int y){
	
	// probar comentar
	putchxy(x,y,' ');
	
}

int main(int argc, char *argv[]) {
	
	cout<<"Con las teclas se mueve (z sale)"<<endl;
	
	int x=10;
	int y=10;
	
	putchxy(x,y,'x'); 
	
	while(true){
		
		
		if(kbhit()) { 
			int tecla=getch();
			
			switch(tecla)
			{
				
			case 75: //izquierda
				
				borrar(x,y); 
				x--;
				dibujar(x,y);
				
				break;
			case 77: //derecha
				
				borrar(x,y); 
				x++;
				dibujar(x,y); 
				
				
				
				break;
			case 72: //arriba
				
				borrar(x,y); 
				y--;
				dibujar(x,y);
				
				break;
			case 80: //abajo
				
				borrar(x,y); 
				y++;
				dibujar(x,y);
				
				break;
			case 'z':
				return 1;
			}
			
			putchxy(x,y,'x');
			
		}
		
	}
	return 0;
}
