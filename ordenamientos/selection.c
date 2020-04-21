#include <stdio.h>

void printArr(int arr[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int i, int menor){
    int temp = arr[i];
    arr[i] = arr[menor];
    arr[menor] = temp;
}

void selectionSort(int arr[], int tam){
    int i, j, menor;
    for(i = 0; i < tam - 1; i++){
        menor = i;
        for(j = i + 1; j < tam; j++){
            if(arr[j] < arr[menor]){
                menor = j;
            }
        }
        swap(arr, i, menor);
    }
}

int main(){
    int arr[] = {4, 8, 2, 5, 10};
    selectionSort(arr, 5);
    printArr(arr, 5);
    return 0;
}
