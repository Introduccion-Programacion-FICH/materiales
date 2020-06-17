#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <conio2.h>

using namespace std;

/* 
Para varios objetos, el metodo de loop es el mismo**/

class Objeto {
		
	// variables para contar
	
	clock_t tempo; //variable para ajustar la velocidad de movimiento de la pelotita
	clock_t paso; //variable para ajustar la velocidad de movimiento de la pelotita
	int velocidad;
	int color;
	
	// contador como ejemplo
	int contador;
	
	
	public:
		Objeto(int vel, int c){
			velocidad = vel;
			paso=CLOCKS_PER_SEC/velocidad; //cada cuanto se permite mover la pelotita 16 veces por segundo
			tempo=clock(); //inicializamos tempo con el reloj
			contador = 50;
			color = c;
		}
		
		bool update();
};


bool Objeto::update(){
	

	
	if (contador > 0){
		if(tempo+paso<clock()){
			textcolor(color);
			for (int i =0;i<contador;i++){
				cout<<">";
			}
			cout<<" "<<contador<<" "<<endl;
			contador--;
			tempo=clock(); // tomamos el tiempo para saber la proxima vez que movemos la pelotita
		}
		return true;
	}
	
	else{return false;};
	
}

class Juego{
	
//	Los colores de conio se pueden encontrar aca:
//		https://code-reference.com/c/conio.h/textcolor
	
	// objeto 1, una vez por segundo
	Objeto *obj1 = new Objeto(1,10); //-> veces por segundo
	// en 3 son 3 veces por segundo 
	
	// objeto 2, dos veces segundo
	Objeto *obj2 = new Objeto(2,11); //-> veces por segundo
	// en 3 son 3 veces por segundo 
	
	
	// objeto 3, 3 veces por segundo
	Objeto *obj3 = new Objeto(3,12); //-> veces por segundo
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
		flag = obj1->update();
		// el objeto 1 es el ultimo en terminar
		obj2->update();
		obj3->update();
		
	}
	
}


	


int main(int argc, char *argv[]) {

	srand(time(NULL));
	Juego J;
	J.play();

	return 0;
}
