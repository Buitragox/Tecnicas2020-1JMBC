#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILENAME 40

long long int countIf = 0, countSwaps = 0;

void printFile(double timeSpent, time_t beginTime, struct tm* finalTime, 
                char* fileName, int size, int arr[], char* algoritmo){
    FILE* file = fopen(fileName, "w");
    fprintf(file, "Algoritmo usado: %s\n", algoritmo);
    fprintf(file, "Hora de inicio: %s", ctime(&beginTime));
    fprintf(file, "Hora al terminar: %s", asctime(finalTime));
    fprintf(file, "Tiempo de ejecución: %f\n", timeSpent);
    fprintf(file, "Numero de elementos: %d\n", size);
    fprintf(file, "Cantidad de comparaciones: %lld\n", countIf);
    fprintf(file, "Cantidad de intercambios: %lld\n", countSwaps);
    int i;
    for(i = 0; i < size; i++){
        fprintf(file,"%d ", arr[i]);
        if(i % 30 == 0 && i != 0){
            fprintf(file, "\n");
        }
    }
    fclose(file);
}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], int size){
    int i, j;
    for(i = 0; i < size; i++){
        for(j = 0; j < size - 1; j++){
            countIf++;
            if(arr[j] > arr[j + 1]){
                countSwaps++;
                swap(arr, j, j + 1);
            }
        }
    }
}

int main(int argc, char * argv[]){
    if(argc != 3){
        //Al ejecutar el programa se debe dar el nombre de archivo de entrada y de salida
        printf("usage %s [input_file_name] [output_file_name]\n", argv[0]);
        return 0;
    }
    int size = 0;
    int* arr = NULL;
    time_t beginTime;
    time_t endTime;
    struct tm* finalTime;
    double timeSpent;
    FILE* fileArr = fopen(argv[1], "rb");
    if(fileArr != NULL){
        fread(&size, sizeof(int), 1, fileArr);
        arr = malloc(sizeof(int) * size);
        fread(arr, sizeof(int), size, fileArr);
        time(&beginTime);
        clock_t begin = clock();
        bubbleSort(arr, size);
        clock_t end = clock();
        time(&endTime);
        finalTime = localtime(&endTime);
        timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
        printFile(timeSpent, beginTime, finalTime, argv[2], size, arr, "bubble sort");
    }
    else{
        fprintf(stderr, "Error al cargar el archivo\n");
    }
    fclose(fileArr);
    free(arr);
    return 0;
}
