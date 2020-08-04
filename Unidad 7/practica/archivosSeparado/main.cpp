#include<iostream>
#include <ctime>
#include <cstdlib>
#include "Juego.h"
using namespace std;

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	Juego J;
	J.play();
	
	return 0;
}

