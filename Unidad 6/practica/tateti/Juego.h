
#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"


class Juego {
	
	char jugador1;
	char jugador2;
	Tablero miTablero;
	
	// posiciona una ficha
	void setFichaIn(int x, int y, char c);
	// imprime pantalla, llama a los otros metodos de imprimir
	void imprmirPantalla(bool turno1, bool opciones=true);
	// imprime opciones
	void imprimirOpciones(bool opciones=true);
	// imprime tablero
	void imprimirTablero();
	// evento de tecla
	int getKey();
	// imprime una tecla en el tablero
	void insertKey(int k,char c);
	// verifica que se haya formado tateti
	bool checkTateti();
	// verifica que haya terminado por tablero completo
	bool checkTermino();
	// imprime ganador
	void imprimirGanador(bool);
	// imprime juego finalizado
	void imprimirTerminar(bool);
	// imprime cabecera
	void imprimirCabecera();
	
public:
	Juego();
	void play();

	
private:
};

#endif

