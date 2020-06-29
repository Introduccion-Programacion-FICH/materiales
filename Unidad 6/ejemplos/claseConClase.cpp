#include<iostream>
#include<stdio.h>
#include <conio2.h>

using namespace std;

/**
Clase Letra
**/

class Letra {
private:
	char caracter;
	int color;
	
public:
	//CONSTRUCTORES
	Letra(char, int);
	Letra(char);
	Letra();
	// SETEAR COLOR
	void setColor(int);
	// OBTENER LETRA
	char getLetra();
	// OBTENER COLOR
	char getColor();
};

// CONSTRUCTOR CARACTER COLOR
Letra::Letra(char _caracter, int _color) {
	color = _color;
	caracter = _caracter;
}
// CONSTRUCTOR CARACTER
Letra::Letra(char _caracter) {
	caracter = _caracter;
}

// CONSTRUCTOR VACIO - Importante para poder instanciar el texto en PALABRA
Letra::Letra() {}
// SETEAR COLOR
void Letra::setColor(int _color) {
	color = _color;
}
// GET LETRA
char Letra::getLetra() {
	return caracter;
}
// GET LETRA
char Letra::getColor() {
	return color;
}

/**
Clase Palabra
**/
class Palabra {
	
private:
	// 100 elementos Letra
	// Esto es posible porque hay un constructor vacio de Letra()
	Letra texto[100];
	int largo;
	
public:
	// CONSTRUCTORES
	Palabra(string);
	Palabra();
	
	// SET COLOR AT POSICION
	void setColorAt(int, int);
	
	// SET COLOR RANDOM EN TODA LA PALABRA
	void randomColor();
	
	// IMPRIMIR PALABRA
	void printPalabra();
	
	// OBTENER TAMANIO
	int getLength();
	
};

// SET PALABRA
Palabra::Palabra(string _palabra){
	// Por cada caracter
	for (int i = 0; i < _palabra.length(); i++) {
		// Creo una Letra con el constructor Letra(char)
		Letra L(_palabra[i]);
		// y lo asigno la elemento i del arreglo de Letra
		texto[i] = L;
	}
	largo = _palabra.length();
}

// SET COLOR AT POSICION
void Palabra::setColorAt(int pos, int col) {
	texto[pos].setColor(col);
}
// SET COLOR EN TODA LA PALABRA, COLORES AL AZAR
/**
PRESTAR ATENCION COMO SE REUTILIZAN LOS COMPONENTES DE CLASE
*/
void Palabra::randomColor(){
	// los colores van de 0 a 15
	for (int i = 0; i < largo; i++){
		setColorAt(i, rand()%15);
	}
}

// Print Palabra
void Palabra::printPalabra() {
	for (int i = 0; i < largo; i++) {
		textcolor(texto[i].getColor());
		cout<<texto[i].getLetra();
	}
}

// OBTENER TAMANIO
int Palabra::getLength() {
	return largo;
}



int main(int argc, char *argv[]) {
	
	
	// creo una palabra
	Palabra abracadabra("abracadabra");
	abracadabra.randomColor();
	abracadabra.printPalabra();
	cout<<endl;
	
	// creo palabra
	Palabra caballo("caballo");
	int colorRojo = RED;
	caballo.setColorAt(0,colorRojo);
	caballo.setColorAt(1,colorRojo);
	caballo.setColorAt(2,colorRojo);
	caballo.setColorAt(3,colorRojo);
	caballo.setColorAt(4,colorRojo);
	caballo.setColorAt(5,colorRojo);
	caballo.setColorAt(6,colorRojo);
	caballo.printPalabra();
	
	return 0;
}


/**
REFERENCIA DE COLORES EN CONIO
https://code-reference.com/c/conio.h/textcolor
**/

