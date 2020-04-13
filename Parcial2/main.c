#include "FuncionesCC.h"

int menu(){
    int opcion;
    printf("\nMenu Centro Comercial\n");
    printf("1. Crear nuevo centro comercial\n");
    printf("2. Aniadir nuevo local\n");
    printf("3. Buscar local por nombre\n");
    printf("4. Buscar locales por piso\n");
    printf("5. Contratar un empleado\n");
    printf("6. Despedir un empleado\n");
    printf("7. Eliminar local\n");
    printf("8. Total de empleados de un piso\n");
    printf("9. Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int main(){
    int numPisos, numLocalesxPiso, opcion;
    local_t ** centroComercial;
	printf("Para comenzar ingresa los siguientes datos\n");
    printf("Numero de pisos del centro comercial: ");
    scanf("%d", &numPisos);
    printf("Numero de locales por piso: ");
    scanf("%d", &numLocalesxPiso);
    local_t ** centroComercial = crearCentroComercial(numPisos, numLocalesxPiso);
    do{
        opcion = menu();
        switch(opcion){
        case 1:
            freeCentroComercial(centroComercial, numPisos);
            printf("Numero de pisos del centro comercial: ");
            scanf("%d", &numPisos);
            printf("Numero de locales por piso: ");
            scanf("%d", &numLocalesxPiso);
            local_t ** centroComercial = crearCentroComercial(numPisos, numLocalesxPiso);
            break;
        case 2:
            int piso, numLocal, check = 0, empleados;
            char nombre[35];
            do{
                printf("Ingrese el piso: ");
                scanf("%d", &piso);
                piso;
                printf("Ingrese el numero de local: ");
                scanf("%d", &numLocal);
                if(piso > 0 && piso <= numPisos){
                    if(numLocal > 0 && numLocal <= numLocalesxPiso){
                        if(centroComercial[piso - 1][numLocalesxPiso - 1].estado == LIBRE){
                            printf("Ingrese el nombre del local: ");
                            scanf("%35s", nombre);
                            printf("Ingrese la cantidad de empleados: ");
                            scanf("%d", empleados);
                            añadirLocal(centroComercial, piso, numLocal, nombre, empleados);
                            check = 1;
                        }
                        else{
                            printf("El local esta ocupado\n");
                        }
                    }
                    else{
                        printf("El numero de local es invalido\n");
                    }
                }
                else{
                    printf("El piso es invalido\n");
                }
            }
            while(check == 0);
            break;

        case 3:
            char nombre[35];
            printf("Ingrese el nombre del local: ");
            scanf("%35s", nombre);
            buscarNombre(centroComercial, numPisos, numLocalesxPiso, nombre);
            break;
        
        case 4:
            int piso;
            printf("Ingrese el piso: ");
            scanf("%d", piso);
            buscarPiso(centroComercial, numPisos, numLocalesxPiso, piso);
            break;

        case 5:
            char nombre[35];
            printf("Ingrese el nombre del local: ");
            scanf("%35s", nombre);
            modificarEmpleados(centroComercial, numPisos, numLocalesxPiso, nombre, opcion);
            break;

        case 6:
            char nombre[35];
            printf("Ingrese el nombre del local: ");
            scanf("%35s", nombre);
            modificarEmpleados(centroComercial, numPisos, numLocalesxPiso, nombre, opcion);
            break;

        case 7:
            char nombre[35];
            printf("Ingrese el nombre del local: ");
            scanf("%35s", nombre);
            eliminarLocal(centroComercial, numPisos, numLocalesxPiso, nombre);
            break;
        
        case 8:
            int piso, total;
            printf("Ingrese el piso: ");
            scanf("%d", piso);
            if(piso > 0 && piso <= numPisos){
                total = totalEmpleados(centroComercial, piso - 1, numLocalesxPiso);
            }
            else{
                printf("Piso invalido");
            }
            break;

        case 9:
            break;

        default:
            printf("Opcion incorrecta\n");
            break;
        }
    }
    while(opcion != 9);
    freeCentroComercial(centroComercial, numPisos);
	return 0;
}