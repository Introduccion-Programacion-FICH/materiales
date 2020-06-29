#include <conio2.h>
#include <iostream>
#include <ctime>



using namespace std;


int main(int argc, char *argv[]) {
	
	cout<<"Muestra las teclas de direccion y las teclas QWERTYASDFGH, con z se sale"<<endl;
	
	
	
	while(true){
		
		
		if(kbhit()) { 
			int tecla=getch();
			
			switch(tecla)
			{
				
			case 75: //izquierda
				cout<<"izquierda"<<endl;
				break;
			case 77: //derecha
				cout<<"derecha"<<endl;
				break;
			case 72: //arriba
				cout<<"arriba"<<endl;
				break;
			case 80: //abajo
				cout<<"abajo"<<endl;
				break;
			case 'q': case 'w': case 'e': case 'r': case 't': case 'y':
			case 'a': case 's': case 'd':case 'f': case 'g': case 'h':
				cout<<"Letra: "<<(char)tecla<<endl;
				break;
			case 'z':
				return 1;
			}
			
		}
		
	}
	return 0;
}
