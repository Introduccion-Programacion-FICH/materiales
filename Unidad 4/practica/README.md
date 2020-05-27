# Guia práctica de arreglos

Del ejercicio 1 al ejercicio 12 son para que puedas ejercitar los conceptos que vimos, no son obligatorios. **El ejercicio 13 debe entregarse**.

### Ejercicio 1
Genera aleatoriamente 10 valores (o lee 10 valores que ingrese el usuario) del 1 a 10 y luego informa si se encuentra el valor 5. Utiliza arreglos. Informalo en pantalla.
*Ejemplo:*

4, 1, 2, 4, **5**, 6, 4, 4, 7, 8 -> Salida: Se encuentra el 5.

### Ejercicio 2
Genera aleatoriamente 20 valores (o lee 20 valores que ingrese el usuario) del 1 a 100 y luego informa cual es el valor más alto. Si se repite, sólo informalo una vez.
*Ejemplo:*

11, 31, 22, 24, 55, 56, 41, 43, 71, 18, **91**, 11, 58, 65, 19, 57, 90, **91**, 84, 47, 24 -> Salida: El más alto es el 91.

### Ejercicio 3
Genera un arreglo de 100 elementos con valores que vayan progresivamente del 1 al 100 (1, 2, 3, 4, ... 100). Almacena en otro arreglo solo aquellos valores pares y en otro solo aquellos impares. Al final deben quedar dos arreglos de 50 valores cada uno. Informa el contenido de ambos arreglos.

### Ejercicio 4
Ingresa un nombre e informa cuántas *“a”* tiene. Repasa la guia de Strings.

### Ejercicio 5
Ingresa un nombre e informa cuántas vocales tiene. Repasa la guia de Strings

### Ejercicio 6
Ingresa un nombre e informa cuántas vocales de cada tipo tiene. Repasa la guia de Strings

### Ejercicio 7
Realiza un arreglo que al recorrerlo por fila y columna muestre en pantalla la siguiente grilla:

```cpp
- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -
```
*Si no se ve bien, son 10 guiones en 10 filas:*



### Ejercicio 8
Realiza un arreglo que al recorrerlo por fila y columna muestre en pantalla la siguiente grilla. Deben usarse sólo los índices de la estructura para llenar el arreglo

```cpp
0 1 2 3 4 5
0 1 2 3 4 5
0 1 2 3 4 5
0 1 2 3 4 5
0 1 2 3 4 5
0 1 2 3 4 5
```

### Ejercicio 9
Realiza un arreglo que al recorrerlo por fila y columna muestre en pantalla la siguiente grilla. Deben usarse sólo los índices de la estructura para llenar el arreglo

```cpp
0 0 0 0 0 0
1 1 1 1 1 1
2 2 2 2 2 2
3 3 3 3 3 3
4 4 4 4 4 4
5 5 5 5 5 5
```
*¿Qué similitud encuentras con el ejercicio anterior? ¿Pudiste reutilizar algún código?*

### Ejercicio 10
Genere un arreglo con 100 valores al azar (el rango del los valores es a gusto de cada uno). Muestrelo en pantalla y luego inviértalo y vuelta a informarlo. 
*Ej: [5, 7, 10, 15, 8, 9] → [9, 8, 15, 10, 7, 5]*

### Ejercicio 11
Genere un arreglo con 20 valores todos en 0 (cero). Pida por consola 4 valores y 4 posiciones. Inserte los valores en sus respectivas posiciones (tener en cuenta que estén dentro del rango)

### Ejercicio 12

Genere dos arreglos con 20 valores al azar entre 1 y 10. Genere un tercer arreglo que sea el resultado de la suma de ambos arreglos. La suma de vectores es elemento a elemento, ejemplo:
    
*[5, 8, 4, 2] y [3, 4, 2, 9] → [5+3, 8+4, 4+2, 2+9] → [8, 12, 6, 11]*

### Ejercicio 13
Deben hacer el juego de cartas Siete y medio.

En este juego de cartas al jugador se le reparten cartas mientras no se pase de 7 y 1/2. El objetivo es acercarse a 7 y medio sin pasarse.
Cada carta vale su valor, las figuras valen 1/2 y se juega con un mazo de 40 cartas (es decir, sin 8 ni 9, ni comodines):
|Carta|Valor|
|--|--|
| 1 | 1 |
| 2 | 2 |
| 3 | 3 |
| 4 | 4 |
| 5 | 5 |
| 6 | 6 |
| 7 | 7 |
| 10 | 1/2 |
| 11 | 1/2 |
| 12 | 1/2 |

Ejemplo: 

*Sale un 3, acumula 3. Pide otra carta.

Sale un 10, acumula 3 y 1/2. Pide otra carta.

Sale un 11, acumula 4. 

Etcétera.* 

Si el jugador decide plantarse antes de pasarse de 7 y 1/2, juega la Computadora que hace lo mismo. Si la computadora empata o le gana al jugador, entonces la PC es quien gana.

**Contemplaciones:**

-   No hace falta que digan de qué palo es la carta, pero tengan en cuenta que una vez que se sacan una carta, esa ya está en el mazo (pueden marcar el mazo o contar los índices)
-   No hace falta que la partida sea eterna, puede hacerse 1 sola vez, aunque si la hacen hasta que el juegador decida dejar de jugar, mejor.

**Ayuda de cómo hacer el mazo**
La mayor dificultad es cómo realizar el mazo para retirar una carta y que no vuelva a salir. Una forma es hacer un mazo con las 40 cartas y quitarlas. O bien, hacer un mazo de valores y otro de *bool* que lleve en cuenta que carta ya salió y cual no. 

Ejemplo:

*Mazo de valores:

1, 2, 3, 4, 5, 6, 7, 10, 11, 12

1, 2, 3, 4, 5, 6, 7, 10, 11, 12

1, 2, 3, 4, 5, 6, 7, 10, 11, 12

1, 2, 3, 4, 5, 6, 7, 10, 11, 12*


*Donde cada columna es un palo.*
