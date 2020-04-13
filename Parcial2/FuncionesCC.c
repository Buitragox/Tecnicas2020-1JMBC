#include "FuncionesCC.h"

local_t ** crearCentroComercial(int numPisos, int numLocalesxPiso){
    local_t ** centroComercial = malloc(sizeof(local_t *) * numPisos);
    int i, j;
    if(centroComercial != NULL){
        for(i = 0; i < numPisos; i++){
            centroComercial[i] = malloc(sizeof(local_t) * numLocalesxPiso);
            if(centroComercial[i] == NULL){
                printf("Error reservando memoria\n");
                exit(1);
            }
            for(j = 0; j < numLocalesxPiso; j++){
                centroComercial[i][j].estado = LIBRE;
            }
        }
    }
    else{
        printf("Error reservando memoria\n");
        exit(1);
    }
    return centroComercial;
}

void aniadirLocal(local_t ** centroComercial, int piso, int numLocal, char nombre[35], int empleados){
    strcpy(centroComercial[piso - 1][numLocal - 1].nombre, nombre);
    centroComercial[piso - 1][numLocal - 1].id = piso * 1000 + numLocal;
    centroComercial[piso - 1][numLocal - 1].piso = piso;
    centroComercial[piso - 1][numLocal - 1].numLocal = numLocal;
    centroComercial[piso - 1][numLocal - 1].estado = OCUPADO;
    centroComercial[piso - 1][numLocal - 1].numEmpleados = empleados;
}

void freeCentroComercial(local_t ** centroComercial, int numPisos){
    int i;
    for(i = 0; i < numPisos; i++){
        free(centroComercial[i]);
    }
    free(centroComercial);
}

void buscarNombre(local_t ** centroComercial, int numPisos, int numLocalesxPiso, char nombre[35]){
	int i, j, encontrado = 0;
    for(i = 0; i < numPisos; i++){
        for(j = 0; j < numLocalesxPiso; j++){
            if(strcmp(centroComercial[i][j].nombre, nombre) == 0 && centroComercial[i][j].estado == OCUPADO){
                printf("ID: %d\n", centroComercial[i][j].id);
                printf("Piso: %d\n", centroComercial[i][j].piso);
                printf("Local numero: %d\n", centroComercial[i][j].numLocal);
                printf("Numero de empleados: %d\n", centroComercial[i][j].numEmpleados);
                encontrado = 1;
                break;
            }
        }
    }
    if(!encontrado){
        printf("No se encontraron locales con ese nombre\n");
    }
}

void buscarPiso(local_t ** centroComercial, int numPisos, int numLocalesxPiso, int piso){
    int i, encontrado = 0;
    piso--;
    if(piso < numPisos && piso >= 0){
        for(i = 0; i < numLocalesxPiso; i++){
            if(centroComercial[piso][i].estado == OCUPADO){
                printf("Local %s\n", centroComercial[piso][i].nombre);
                printf("ID: %d\n", centroComercial[piso][i].id);
                printf("Piso: %d\n", centroComercial[piso][i].piso);
                printf("Local numero: %d\n", centroComercial[piso][i].numLocal);
                printf("Numero de empleados: %d\n", centroComercial[piso][i].numEmpleados);
                printf("================================\n");
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
    int i, j, encontrado = 0;
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
                encontrado = 1;
                break;
            }
        }
    }
    if(!encontrado){
        printf("No se encontraron locales con ese nombre\n");
    }
}

void eliminarLocal(local_t ** centroComercial, int numPisos, int numLocalesxPiso, char nombre[35]){
    int i, j, encontrado = 0;
    for(i = 0; i < numPisos; i++){
        for(j = 0; j < numLocalesxPiso; j++){
            if(strcmp(centroComercial[i][j].nombre, nombre) == 0 && centroComercial[i][j].estado == OCUPADO){
                centroComercial[i][j].estado = LIBRE;
                encontrado = 1;
                break;
            }
        }
    }
    if(!encontrado){
        printf("No se encontraron locales con ese nombre\n");
    }
}

int totalEmpleados(local_t ** centroComercial, int piso, int numLocalesxPiso){
    if(numLocalesxPiso == 0){
        return 0;
    }
    else{
        int empleados = centroComercial[piso][numLocalesxPiso - 1].numEmpleados;
        return empleados + totalEmpleados(centroComercial, piso, numLocalesxPiso - 1);
    }
}