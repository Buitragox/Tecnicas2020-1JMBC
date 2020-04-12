#include "FuncionesCC.h"

local_t ** crearCentroComercial(int numPisos, int numLocalesxPiso){
    local_t ** centroComercial = malloc(sizeof(local_t *) * numPisos);
    int i, j;
    if(centroComercial != NULL){
        for(i = 0; i < numPisos; i++){
            centroComercial[i] = malloc(sizeof(local_t) * numLocalesxPiso);
            if(centroComercial[i] == NULL){
                printf("Error reservando memoria");
                exit(1);
            }
            for(j = 0; j < numLocalesxPiso; j++){
                centroComercial[i][j].estado = LIBRE;
            }
        }
    }
    else{
        printf("Error reservando memoria");
        exit(1);
    }
    return centroComercial;
}

void freeCentroComercial(local_t ** centroComercial, int numPisos){
    int i;
    for(i = 0; i < numPisos; i++){
        free(centroComercial[i]);
    }
    free(centroComercial);
}

void buscarNombre(local_t ** centroComercial, int numPisos, int numLocalesxPiso, char nombre[35]){
	int i, j;
    for(i = 0; i < numPisos; i++){
        for(j = 0; j < numLocalesxPiso; j++){
            if(strcmp(centroComercial[i][j].nombre, nombre) == 0 && centroComercial[i][j].estado == OCUPADO){
                printf("ID: %d\n", centroComercial[i][j].id);
                printf("Piso: %d\n", centroComercial[i][j].piso);
                printf("Local numero: %d\n", centroComercial[i][j].numLocal);
                printf("Numero de empleados: %d\n", centroComercial[i][j].numEmpleados);
                break;
            }
        }
    }
    printf("No se encontraron locales con ese nombre\n");
}

void buscarPiso(local_t ** centroComercial, int numPisos, int numLocalesxPiso, int piso){
    int i, encontrado = 0;
    piso--;
    if(piso < numPisos){
        for(i = 0; i < numLocalesxPiso; i++){
            if(centroComercial[piso][i].estado == OCUPADO){
                printf("Local %s\n", centroComercial[piso][i].nombre);
                printf("ID: %d\n", centroComercial[piso][i].id);
                printf("Piso: %d\n", centroComercial[piso][i].piso);
                printf("Local numero: %d\n", centroComercial[piso][i].numLocal);
                printf("Numero de empleados: %d\n", centroComercial[piso][i].numEmpleados);
                printf("================================");
                encontrado = 1;
            }
        }
        if(!encontrado){
            printf("No se encontraron locales en este piso\n");
        }
    }
    else{
        printf("Piso invalido\n");
    } 
}

void modificarEmpleados(local_t ** centroComercial, int numPisos, 
                        int numLocalesxPiso, char nombre[35], int opcion){
    int i, j;
    for(i = 0; i < numPisos; i++){
        for(j = 0; j < numLocalesxPiso; j++){
            if(strcmp(centroComercial[i][j].nombre, nombre) == 0 && centroComercial[i][j].estado == OCUPADO){
                if(opcion == 5){
                    centroComercial[i][j].numEmpleados++;
                    printf("Empleado contratado\n");
                }
                else{
                    centroComercial[i][j].numEmpleados--;
                    printf("Empleado despedido\n");
                }
                break;
            }
        }
    }
    printf("No se encontraron locales con ese nombre\n");
}