#include "funciones.h"
/* Código ordenado, bonito, funcional. Solo le quitaría esos while(1) que son muy feos */

void agregarDia(persona lista[][MAX], int mes, int dispo[]){
	int dia;
	printf("Ingrese el dia de nacimiento\n");
    fflush(stdin);
	scanf("%d", &dia);
	while(1){
		if(mes == 1 && dia > 0 && dia <= 29){
			break;
		}
		else if(mes != 1 && dia > 0 && dia <= 31){
			break;
		}
		printf("Dia invalido\n");
		printf("Ingrese el dia de nacimiento\n");
		fflush(stdin);
		scanf("%d", &dia);
	}
    lista[mes][dispo[mes]].dia = dia;
}

void agregarAnio(persona lista[][MAX], int mes, int dispo[]){
	int anio;
	printf("Ingrese el anio de nacimiento\n");
    fflush(stdin);
	scanf("%d", &anio);
	while(1){  // Luisa: en general no me gusta el while 1. Lo podrías hacer más bonito
		if(anio >= 0 && anio <= 2020){
			break;
		}
		printf("Anio invalido\n");
		printf("Ingrese el anio de nacimiento\n");
		fflush(stdin);
		scanf("%d", &anio);
	}
    lista[mes][dispo[mes]].anio = anio;
}

void agregarUsuario(persona lista[12][MAX], int dispo[]){
    int mes;
    printf("Ingrese el mes de nacimiento\n");
    fflush(stdin);
    scanf("%d", &mes);
	mes--;
    if(mes >= 0 && mes <= 11 && dispo[mes] < MAX){
        printf("Ingrese el nombre del usuario\n");
        fflush(stdin);
        scanf("%s", lista[mes][dispo[mes]].nombre);
        agregarDia(lista, mes, dispo);
        lista[mes][dispo[mes]].mes = mes;
        agregarAnio(lista, mes, dispo);
        dispo[mes]++;
    } 
    else{
        printf("No hay cupo o el mes que ha ingresado no es valido.\n");
    }
}

void numeroSuerte(persona lista[12][MAX], int dispo[]){
    srand(time(NULL));
    int luckyNum; 
    suerte num = 0;
    int i, j, aprov = 0;
    char nombre[20];
    printf("Ingresa tu nombre\n");
    fflush(stdin);
    scanf("%s", nombre);
    for(i = 0; i < 12; i++){
        for(j = 0; j < dispo[i]; j++){
            if(strcmp(nombre, lista[i][j].nombre) == 0){
                aprov = 1;
                num = lista[i][j].mes + 1;
                break;
            }
        }
    } 
    if(aprov == 1){
        switch(num){
            case ENERO:
                printf("Tu numero de la suerte es 54657\n");
                break;
            case FEBRERO:
                printf("Tu numero de la suerte es 99873\n");
                break;
            case MARZO:
                printf("Tu numero de la suerte es 23763\n");
                break;
            case ABRIL:
                printf("Tu numero d ela suerte es 91735\n");
                break;
            case MAYO:
                printf("Tu numero de la suerte es 65283\n");
                break;
            case JUNIO:
                printf("Tu numero de la suerte es 31416\n");
                break;
            case JULIO:
                printf("Tu numero de la suerte es 66839\n");
                break;
            case AGOSTO:
                printf("Tu numero de la suerte es 69696\n");
                break;
            case SEPTIEMBRE:
                printf("Tu numero de la suerte es 42020\n");
                break;
            case OCTUBRE:
                printf("Tu numero de la suerte es 54321\n");
                break;
            case NOVIEMBRE:
                printf("Tu numero de la suerte es 09876\n");
                break;
            case DICIEMBRE:
                printf("Tu numero de la suerte es 12398\n");
                break;
            default:
                printf("El mes ingresado no es valido\n");
		}
    }
    else{
        printf("El usuario ingresado no esta registrado.\n");
    }
}


void mostrarCumpleanios(persona lista[12][MAX], int dispo[]){
	int mes, i;
	printf("Ingrese el mes: ");
	scanf("%d", &mes);
	mes--;
	if(mes >= 0 && mes <= 11){
		printf("Los que cumplen anios son:\n");
		for(i = 0; i < dispo[mes]; i++){
			printf("%s\n", lista[mes][i].nombre);
		}
	}
	else{
		printf("%d es un mes invalido\n", mes);
	}
}

int sumaEdades(persona lista[12][MAX], int dispo[], int perAct, int mes){
	int edad = 0;
	if(perAct == 0){
		return 0;
	}
	else{
		edad = 2020 - lista[mes][perAct - 1].anio;
		return edad + sumaEdades(lista, dispo, perAct - 1, mes);
	}
}

void promedioEdades(persona lista[12][MAX], int dispo[]){
	int suma, mes;
	float prom = 0;
	printf("Ingrese el mes: ");
	scanf("%d", &mes);
	mes--;
	suma = sumaEdades(lista, dispo, dispo[mes], mes);
    if(dispo[mes]){
	    prom = (float)suma / (float)dispo[mes];
    }
	printf("El promedio de edad es: %f\n", prom);
}