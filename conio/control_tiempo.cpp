#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <conio2.h>

using namespace std;

/* 
	El control del tiempo consiste en utilizar el reloj de la PC
	El metodo que utilizamos es tomar el tiempo actual y esperar que 
pase cierto tiempo antes de actualizar la medida nuevamente:
	Ej:
	tomamos el tiempo actual tiempo actual 0 ml (milisegundos)
	Queremos que nuestro objeto, contador, reaccione cada 1 segundos (1000 milisegundos)
	Declaramos una variable paso de 1000.
	Dentro de un bucle infinito empezamos a tomar el tiempo, cuando el tiempo sea mayor o igual al paso
	actualizamos el nuevo tiempo, que será, el tiempo actual + 1000
*/

int main(int argc, char *argv[]) {
	
	clock_t tempo; //variable para ajustar la velocidad de movimiento de la pelotita
	clock_t paso; //variable para ajustar la velocidad de movimiento de la pelotita
	int velocidad;
	cout << "Ingresar la velocidad (veces por segundo)"<<endl;
	cin >> velocidad;
	
	paso=CLOCKS_PER_SEC/velocidad; //cada cuanto se permite mover la pelotita 16 veces por segundo
	tempo=clock(); //inicializamos tempo con el reloj
	int contador = 50;
	
	
	while(contador>0) {
		
		if(tempo+paso<clock()){
			
			cout<<"contador: "<<contador<<endl;
			contador--;
			tempo=clock(); // tomamos el tiempo para saber la proxima vez que movemos la pelotita
		}
	}
	return 0;
}
