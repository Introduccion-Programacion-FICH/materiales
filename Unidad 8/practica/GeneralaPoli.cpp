#include<iostream>
#include<conio2.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

class Ficha{
private:
	
protected:
	bool vacio;
	int nro;
public:
	Ficha(int c){nro = c;};
	Ficha(){};	
	virtual void mostrar(){};
	virtual int getNro(){return nro;}
	void setVacio(){vacio = true;}
	void cancelVacio(){vacio = false;}
	bool isVacio(){return vacio;}
};

class Carta: public Ficha{
	string palo;
	int cod_palo;
	int color;
	
public:
	
	Carta(int _nro, int cod_palo);
	Carta(Carta *c);
	Carta(void){};  // Siempre es bueno tener un constructor vacio por defecto
	string getPalo(){return palo;}
	void mostrar();
};


Carta::Carta(Carta *c){
	vacio = false;
	nro = c->getNro();
	cod_palo = c->cod_palo;
	vacio = false;
	
}

Carta::Carta(int _nro, int _codPalo){
	vacio = false;
	nro = _nro;
	cod_palo = _codPalo;
	vacio = false;
	
	// definicion del palo
	switch (cod_palo){
	case 1:
		palo = "D";
		color = 12;
		break;
	case 2:
		palo = "C";
		color = 12;
		break;
	case 3:
		palo = "P";
		color = 15;
		break;
	case 4:
		palo = "T";
		color = 15;
		break;
	}
}

void Carta::mostrar(){
	if(!isVacio()){
		textcolor(color);
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


class Dado : public Ficha{
private:
	void generar();
public:
	Dado();
	void mostrar();
	
};

Dado::Dado(){
	
	vacio = false;
	generar();
}


void Dado::generar(){
	if(!vacio){
		nro = ((rand()%6)+1);
	}
}

void Dado::mostrar(){

	textcolor(13);
	cout<<nro<<endl;
	textcolor(8);
}

class Mano{
	
	Ficha *mano[5];
	
public:
	Mano();
	void sort();
	void generarManoCartas();
	void mostrarMano();
	Ficha* getIndex(int c);
	
};

 Mano::Mano(){
	
		mano[0] = new Dado();
		mano[1] = new Dado();
		mano[2] = new Dado();
		mano[3] = new Dado();
		mano[4] = new Dado();

}

void Mano::mostrarMano(){
	
	for( int i = 0; i<5; i++){
		mano[i]->mostrar();
	}
}

Ficha* Mano::getIndex(int i){return mano[i];}


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

class ReglasGenerala{
public:
	int JuegoNro(Mano *m,int v);
	bool Generala(Mano *m);
};

bool ReglasGenerala::Generala(Mano *_m){
	
	if(_m->getIndex(0)->getNro() == _m->getIndex(4)->getNro()){
		return true;
	}
	   return false;
}

int ReglasGenerala::JuegoNro(Mano *_m, int nro){
	
	int suma = 0;
	for (int i=0;i<5;i++){
		if(_m->getIndex(i)->getNro() == nro){
			suma += _m->getIndex(i)->getNro();
		}
	}
	return suma;
}

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




class Jugador{
	
	Mano *miMano = new Mano();
public:
	Jugador();
	void mostrarMano();
	Mano* getMano();
	
	
	
};

Jugador::Jugador(){}


void Jugador::mostrarMano(){
	miMano->mostrarMano();
	
}

Mano* Jugador::getMano(){return miMano;}







int main (int argc, char *argv[]) {
	
	
	srand (time(NULL));
	Jugador *J = new Jugador();
	J->getMano()->mostrarMano();
	cout<<endl<<"ordenado:"<<endl;
	J->getMano()->sort();
	
	cout<<endl;
	
	J->getMano()->mostrarMano();
	cout<<endl;
	
	Reglas *R = new Reglas();
	
	cout<<endl<<"Puntos al 1 "<<R->JuegoNro(J->getMano(),1)<<endl;
	cout<<endl<<"Puntos al 2 "<<R->JuegoNro(J->getMano(),2)<<endl;
	cout<<endl<<"Puntos al 3 "<<R->JuegoNro(J->getMano(),3)<<endl;
	cout<<endl<<"Puntos al 4 "<<R->JuegoNro(J->getMano(),4)<<endl;
	cout<<endl<<"Puntos al 5 "<<R->JuegoNro(J->getMano(),5)<<endl;
	cout<<endl<<"Puntos al 6 "<<R->JuegoNro(J->getMano(),6)<<endl;
	cout<<"Es Escalera "<<R->Escalera(J->getMano());
	cout<<endl<<"Es Poker "<<R->Poker(J->getMano());
	cout<<endl<<"Es Full "<<R->Full(J->getMano());
	cout<<endl<<"Es Generala "<<R->Generala(J->getMano());
	
	cout<<endl;
	getchar();
	
	
	
	
	
	return 0;
}

