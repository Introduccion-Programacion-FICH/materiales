#include<iostream>
#include<conio2.h>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
CLASE MADRE FICHA. 
*/
// La mano se compone de Fichas que
// se hacen polimorficas con Dado y Carta

class Ficha{
private:
	
protected:
	bool vacio;
	int nro;
public:
	// Constructores
	Ficha(int c){nro = c;};
	Ficha(){};	
	// Metodos que pueden ser sobreescritos
	virtual void mostrar(){};
	virtual int getNro(){return nro;}
	// set vacio o fijo sirve para sacar o fijar un dado o carta del mazo o la Mano
	void setVacio(){vacio = true;}
	void cancelVacio(){vacio = false;}
	bool isVacio(){return vacio;}
};

/**
CLASE MADRE CARTA.
Hereda de Ficha (Polimorfismo)
*/
// Redefine mostrar

class Carta: public Ficha{
	string palo;
	int cod_palo;
	int color;
	
public:
	
	Carta(int _nro, int cod_palo);
	Carta(void){};  // Siempre es bueno tener un constructor vacio por defecto
	void mostrar();
};



// Constructor de nro y palo

Carta::Carta(int _nro, int _codPalo){
	vacio = false;
	nro = _nro;
	cod_palo = _codPalo;
	vacio = false;
	
	// definicion del palo
	switch (cod_palo){
	case 1:
		// Diamante
		palo = "D";
		color = 12;
		break;
	case 2:
		// Corazon
		palo = "C";
		color = 12;
		break;
	case 3:
		// Pica
		palo = "P";
		color = 15;
		break;
	case 4:
		// Trebol
		palo = "T";
		color = 15;
		break;
	}
}


void Carta::mostrar(){
	if(!isVacio()){
		textcolor(color);
		// Si son las letras, muestro las letras
		// A, J, Q, K
		switch(nro){
			case 1: cout<<"A"; break;
			case 11: cout<<"J"; break;
			case 12: cout<<"Q"; break;
			case 13: cout<<"K"; break;
		default: cout<<nro;
		}
		
		textcolor(color);
	}else{
		cout<<-1;
	}
	cout<< palo;
	cout<<endl;
	textcolor(8);
}


/**
CLASE MANO
*/
// Mano contiene un arreglo de 5 fichas

class Mano{
	
	Ficha *mano[5];
	
public:
	// Constructor
	Mano(){};
	// Ordena (se llama antes de cualquier regla)
	void sort();
	// Muestra Carta por Carta
	void mostrarMano();
	// Genera la mano de Cartas (agregar un metodo que haga lo mismo con dados)
	void generarManoCartas();
	// Obtiene una ficha de la mano
	Ficha* getIndex(int c);
	
};

void Mano::generarManoCartas(){

	// En la generacion de mano se genera un mazo completo y 
	//luego se extraen 5 al azar
	
	Ficha *mazoGrande[52];
	
	// genero el mazo aleatoriamente
	for (int i = 0; i<13; i++){
		
		// Cada Ficha es una Carta!!!
		Ficha *c1 = new Carta(i+1,1);
		Ficha *c2 = new Carta(i+1,2);
		Ficha *c3 = new Carta(i+1,3);
		Ficha *c4 = new Carta(i+1,4);
		
		mazoGrande[i] = c1;
		mazoGrande[i+13] = c2;
		mazoGrande[i+26] = c3;
		mazoGrande[i+39] =c4;
		
	}
	
	for( int i = 0; i<5; i++){
		int id = rand()%52;
		if(!mazoGrande[id]->isVacio()){
			mano[i] = mazoGrande[id];
			mazoGrande[id]->setVacio();
		}
	}
	
	for( int i = 0; i<5; i++){
		mano[i]->cancelVacio();
	}
	
}


void Mano::mostrarMano(){
	
	for( int i = 0; i<5; i++){
		mano[i]->mostrar();
	}
}

// Retorna una ficha de la mano del indice pasado por parametro
Ficha* Mano::getIndex(int i){return mano[i];}


// ordenar
void Mano::sort() {
	
	int i, j, min;
	int n = 5;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (mano[j]->getNro() < mano[min]->getNro())
				min = j;
		Ficha *temp = mano[i];
		mano[i] = mano[min];
		mano[min] = temp;
	}
}

/**
CLASE REGLAS GENERALA (completar)
Madre de Reglas
*/
// A partir de una mano, retorna si se cumple una regla
// agregar las reglas para la generala.


class ReglasGenerala{
};


/**
CLASE REGLAS Poker (completar)
Madre de Reglas
*/
// A partir de una mano, retorna si se cumple una regla de Poker

class ReglasPoker{
public:
	Ficha* CartaAlta(Mano *m);
	bool Par(Mano *m);
	bool DosPares(Mano *m);
	bool Pierna(Mano *m);
};



Ficha* ReglasPoker::CartaAlta(Mano *_m){
	if(_m->getIndex(0)->getNro() == 1)
		{return _m->getIndex(0);}
	return _m->getIndex(4);
}

bool ReglasPoker::Par(Mano *_m){
	
	if(_m->getIndex(0)->getNro() == _m->getIndex(1)->getNro() ||
	   _m->getIndex(1)->getNro() == _m->getIndex(2)->getNro() ||
	   _m->getIndex(2)->getNro() == _m->getIndex(3)->getNro() || 
		_m->getIndex(3)->getNro() == _m->getIndex(4)->getNro()){
		return true;
	}
		return false;
}

bool ReglasPoker::Pierna(Mano *_m){
	
	if(_m->getIndex(0)->getNro() == _m->getIndex(2)->getNro() ||
	   _m->getIndex(1)->getNro() == _m->getIndex(3)->getNro() ||
	   _m->getIndex(2)->getNro() == _m->getIndex(4)->getNro()){
		return true;
	}
	   return false;
}

bool ReglasPoker::DosPares(Mano *_m){
	
	if(
	   (_m->getIndex(0)->getNro() == _m->getIndex(1)->getNro() &&
	   _m->getIndex(2)->getNro() == _m->getIndex(3)->getNro())
	   ||
	   (_m->getIndex(0)->getNro() == _m->getIndex(1)->getNro() &&
		_m->getIndex(3)->getNro() == _m->getIndex(4)->getNro())
	   ||
	   (_m->getIndex(1)->getNro() == _m->getIndex(2)->getNro() &&
		_m->getIndex(3)->getNro() == _m->getIndex(4)->getNro())
	   ){
		return true;
	}
	   return false;
}

/**
CLASE REGLAS 
Hereda de Reglas de Poker y Reglas de Generala
Contiene los metodos comunes a ambos juegos
Full, Poker, Escalera
*/
// A partir de una mano, retorna si se cumple una regla

class Reglas: public ReglasPoker, public ReglasGenerala{
	public:
		Reglas(){};
		bool Escalera(Mano *_m);
		bool Poker(Mano *m);
		bool Full(Mano *m);

	
};

bool Reglas::Escalera(Mano *_m){
	
	int id = 4;
	while (id > 0){
		if(_m->getIndex(id)->getNro() != 
		   (_m->getIndex(id-1)->getNro())+1){
			
			return false;
		}
		id--;
	}
	return true;
}

bool Reglas::Poker(Mano *_m){

	if(_m->getIndex(1)->getNro() == _m->getIndex(2)->getNro() &&
	   _m->getIndex(2)->getNro() == _m->getIndex(3)->getNro() &&
	   (_m->getIndex(0)->getNro() == _m->getIndex(1)->getNro() || 
		_m->getIndex(4)->getNro() == _m->getIndex(3)->getNro())){
		return true;
	}
	   return false;
}

//
//
bool Reglas::Full(Mano *_m){
	
	if(_m->getIndex(0)->getNro() == _m->getIndex(1)->getNro() &&
	   _m->getIndex(3)->getNro() == _m->getIndex(4)->getNro() &&
	   (_m->getIndex(2)->getNro() == _m->getIndex(3)->getNro() ||
		_m->getIndex(2)->getNro() == _m->getIndex(1)->getNro())){
		return true;
	}
	   return false;
}


/**
CLASE Jugador 
El juegador tiene una mano
*/
// Modificar el constructor para que llame al metodo que genera la mano de dados

class Jugador{
	
	Mano *miMano = new Mano();
public:
	Jugador();
	void mostrarMano();
	Mano* getMano();

	
	
};

Jugador::Jugador(){
	// Modificar para en vez de llamar al metodo que genera la mano de cartas, genere la mano de Dados
	miMano->generarManoCartas();
}

void Jugador::mostrarMano(){
	miMano->mostrarMano();
	
}

Mano* Jugador::getMano(){return miMano;}







int main (int argc, char *argv[]) {
	
	// Jugador
	srand (time(NULL));
	Jugador *J = new Jugador();
	J->getMano()->mostrarMano();
	J->getMano()->sort();
	// Ordeno para llamar a las reglas
	cout<<endl<<"ordenado:"<<endl;
	
	J->getMano()->mostrarMano();
	cout<<endl;
	
	// Creo un objeto Reglas general (Hija)
	Reglas *R = new Reglas();
	
	// Pregunto por cada juego
	
	cout<<endl<<"Carta Alta ";R->CartaAlta(J->getMano())->mostrar();
	cout<<"Es Escalera "<<R->Escalera(J->getMano());
	cout<<endl<<"Es Poker "<<R->Poker(J->getMano());
	cout<<endl<<"Es Full "<<R->Full(J->getMano());
	cout<<endl<<"Es Par "<<R->Par(J->getMano());
	cout<<endl<<"Es dos pares "<<R->DosPares(J->getMano());
	cout<<endl<<"Es pierna "<<R->Pierna(J->getMano());
	

	
	
	return 0;
}

