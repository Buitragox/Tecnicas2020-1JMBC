#ifndef FUNCIONESCC_H
#define FUNCIONESCC_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Enumeracion para los estados ocupado y libre
typedef enum Estado{
    OCUPADO, LIBRE
} estado_t;

//Struct de los locales 
typedef struct Local{
	char nombre[35];
	int id;
	int piso; //Fila
	int numLocal; //Columna
	int estado; //Estado del local: libre o ocupado
    int numEmpleados; //Numero de empleados del local
} local_t;

//Función que permite crear la matriz del centro comercial
local_t crearCentroComercial(int numPisos, int numLocalesxPiso);

//Función que añade cada local poniendo los datos en su respectiva posición en la matriz
void añadirLocal(local_t ** centroComercial, int piso, int numLocal, char nombre[35], int empleados);

//Función que libera la matriz del centro comercial de la memoria
void freeCentroComercial(local_t ** centroComercial, int numPisos);

//Función que muestra la información de un local al buscarlo por su nombre
void buscarNombre(local_t ** centroComercial, int numPisos, int numLocalesxPiso, char nombre[35]);

//Función que muestra la información de todos los locales de un piso
void buscarPiso(local_t ** centroComercial, int numPisos, int numLocalesxPiso, int piso);

//Función que permite contratar o despedir un empleado de un local
void modificarEmpleados(local_t ** centroComercial, int numPisos, 
                        int numLocalesxPiso, char nombre[35], int opcion);

//Función que elimina un local de la matriz al ponerlo como libre
void eliminarLocal(local_t ** centroComercial, int numPisos, int numLocalesxPiso, char nombre[35]);

//Función que da el total de empleados de un piso
int totalEmpleados(local_t ** centroComercial, int piso, int numLocalesxPiso);

#endif
