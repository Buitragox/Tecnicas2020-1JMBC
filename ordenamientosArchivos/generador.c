#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int arr[], int pos1, int pos2){
   int temp = arr[pos1];
   arr[pos1] = arr[pos2];
   arr[pos2] = temp;
}

void shuffle(int arr[], int size){
   int i, pos1, pos2;
   for(i = 0; i < size / 2; i++){
      pos1 = rand() % size;
      pos2 = rand() % size;
      swap(arr, pos1, pos2);
   }
}

void save(int arr[], char * fileName, int size){
    FILE * f = fopen(fileName, "wb");
    fwrite(&size, sizeof(int), 1, f);
    fwrite(arr, sizeof(int), size, f);
    fclose(f);
}

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("usage %s [sorted_file_name] [unsorted_file_name]", argv[0]);
        return 0;
    }
    srand(time(NULL));
    int size;
    printf("size: ");
    scanf("%d", &size);
    int * sorted = malloc(sizeof(int) * size);
    int * unsorted = malloc(sizeof(int) * size);
    int i;
    for(i = 0; i < size; i++){
        sorted[i] = i + 1;
        unsorted[i] = i + 1;
    }
    shuffle(unsorted, size);
    save(sorted, argv[1], size);
    save(unsorted, argv[2], size);
    free(sorted);
    free(unsorted);
    return 0;
}