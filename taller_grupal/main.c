#include "funciones.h"

void mostrarMenu(){
	int opcion = 0;
	persona lista[12][MAX];
    int dispo[12] = {0};
	int suma, mes;
	float prom;
  	do{
    	printf("\nOpciones del menu\n");
    	printf("1. Ingresar nuevo usuario.\n");
        printf("2. Mostrar mes.\n");
        printf("3. Promediar las edades\n");
        printf("4. Arrojar numero suerte\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 0:
                break;
            case 1:
				agregarUsuario(lista, dispo);
                break;
            case 2:
                mostrarCumpleanios(lista, dispo);
                break;
            case 3:
				promedioEdades(lista, dispo);
                break;
            case 4:
                numeroSuerte(lista, dispo);
                break;
			default:
				printf("La opcion ingresada no es valida\n");
        }
  	} while(opcion != 0);
}

int main(){
  	mostrarMenu();
  	return 0;
}