#ifndef FICHA_H
#define FICHA_H



class Ficha {
private:
	char figura;
public:
	Ficha();
	Ficha(char);
	// pinta una figura en la ficha
	void setFigura(char);
	// retorna la figura de la ficha
	char getFigura();
	// compara si la ficha es igual a la ficha pasada por parametro
	bool compare(Ficha f);
};

#endif

