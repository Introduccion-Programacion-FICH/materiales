#ifndef AUTO2_H
#define AUTO2_H
#include <ctime>

class Auto2 {
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
	bool cambio;
	clock_t tempo; //variable para ajustar la velocidad de movimiento de la pelotita
	clock_t paso; //variable para ajustar la velocidad de movimiento de la pelotita
	int velocidad;
	int colorAuto;
	
	
public:
	void dibujar();
	void borrar(); // para dibujar, antes debemor borrar
	Auto2(int v, int x0,int y0);
	void setLimit(int, int,int, int);
	Auto2(){};
	void Cambio();
	int getX(){return x;}
	int getY(){return y;}
	void update();
	
	
	
};


#endif

