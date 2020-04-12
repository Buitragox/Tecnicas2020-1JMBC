#include "FuncionesCC.h"

local_t ** crearCentroComercial(int numPisos, int numLocalesxPiso){
    local_t ** centroComercial = malloc(sizeof(local_t *) * numPisos);
    int i, j;
    if(centroComercial != NULL){
        for(i = 0; i < numPisos; i++){
            centroComercial[i] = malloc(sizeof(local_t) * numLocalesxPiso);
            if(centroComercial[i] == NULL){
                printf("Error reservando memoria");
                break;
            }
            for(j = 0; j < numLocalesxPiso; j++){
                centroComercial[i][j].estado = LIBRE;
            }
        }
    }
    else{
        printf("Error reservando memoria");
    }
    return centroComercial;
}

void mostrarLocal(local_t ** centroComercial, int numPisos, int numLocalesxPiso){
	
}
