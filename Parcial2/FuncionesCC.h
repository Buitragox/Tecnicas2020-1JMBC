#ifndef FUNCIONESCC_H
#define FUNCIONESCC_H
#include <stdlib.h>
#include <stdio.h>

//Local 
typedef struct Local{
	char nombre[35];
	int id;
	int piso; //Fila
	int numLocal;//Columna
	// Completelo con lo que quiera
} local_t;

local_t crearCentroComercial();

//Función que muestra la información de un local
void mostrarLocal(local_t ** centroComercial, int numPisos, int numLocalesxPiso);


#endif
