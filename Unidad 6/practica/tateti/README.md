
# Actividad Objetos
## Tateti
### Reglas
- Juego para dos personas
- El juego finaliza cuando se completa el tablero o alguien logra colocar 3 fichas en fila
### Asistencia técnica
Brindamos algunas clases que podrían utilizar como punto de partida o en su totalidad. No es obligatorio su uso, pero sí debe haber al menos 2 clases.

**Clase Ficha:**

Pose la figura y un método de comparación.

**Clase Tablero:**

Posee 9 Fichas que componen el tablero, métodos de visualización y algunos métodos de gestión.

**Clase Juego:**

Posee un Tablero y todos los métodos de gestión e impresión en pantalla.

**main.cpp**

El main sólo crea la instancia del Juego y ejecuta el método play.
```c++
#include<iostream>
#include "Juego.h"
using namespace std;

int main (int argc, char *argv[]) {

	Juego J;
	J.play();
	
	return 0;
}
```
