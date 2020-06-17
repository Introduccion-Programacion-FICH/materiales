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

class Objeto {
		
	// variables para contar
	
	clock_t tempo; //variable para ajustar la velocidad de movimiento de la pelotita
	clock_t paso; //variable para ajustar la velocidad de movimiento de la pelotita
	int velocidad;

	
	// contador como ejemplo
	int contador;
	
	
	public:
		Objeto(int vel){
			velocidad = vel;
			paso=CLOCKS_PER_SEC/velocidad; //cada cuanto se permite mover la pelotita 16 veces por segundo
			tempo=clock(); //inicializamos tempo con el reloj
			contador = 50;
			
		}
		
		bool update();
};


bool Objeto::update(){
	
	if(tempo+paso<clock()){
		cout<<"contador: "<<contador<<endl;
		contador--;
		tempo=clock(); // tomamos el tiempo para saber la proxima vez que movemos la pelotita
	}
	
	if (contador == 0){
		return false;
	}
	
	return true;
	
}

class Juego{
	

	Objeto *obj = new Objeto(3); //-> veces por segundo
	// en 3 son 3 veces por segundo 
	
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
		flag = obj->update();
		
	}
	
}


	


int main(int argc, char *argv[]) {

	Juego J;
	J.play();

	return 0;
}
