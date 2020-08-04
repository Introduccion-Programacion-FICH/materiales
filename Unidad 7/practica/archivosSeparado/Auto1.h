#ifndef AUTO1_H
#define AUTO1_H
#include <ctime>

class Auto1 {
protected:
	int x;
	int y;
	// hago matrices lo suficientemente grandes
	int matriz[5][4];
	int color[5][4]; // matriz de colores
	int ancho;
	int alto;
	int pasoX;
	int pasoY;
	int xnueva;
	int ynueva;
	int maxLimitX;
	int maxLimitY;
	int minLimitX;
	int minLimitY;
	
	
	
	clock_t tempo; //variable para ajustar la velocidad de movimiento de la pelotita
	clock_t paso; //variable para ajustar la velocidad de movimiento de la pelotita
	int velocidad;
	
public:
	void dibujar();
	void borrar(); // para dibujar, antes debemor borrar
	Auto1(int v, int x0,int y0);
	void setLimit(int, int,int, int);
	Auto1(){};
	bool update();
	int getX(){return x;}
	int getY(){return y;}

	
	
};

#endif
