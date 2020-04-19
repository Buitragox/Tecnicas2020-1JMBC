#include <stdio.h>

void printArr(int arr[], int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high){
    int i = low - 1;
    int j;
    for(j = low; j < high; j++){
        if(arr[j] < arr[high]){
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int piv = partition(arr, low, high);
        quickSort(arr, low, piv - 1);
        quickSort(arr, piv + 1, high);
    }
}

int main(){
    int arr[] = {9, 7, 8, 4, 1, 5};
    quickSort(arr, 0, 5);
    printArr(arr, 6);
    return 0;
}
