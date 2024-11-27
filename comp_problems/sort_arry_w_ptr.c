#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort_descending(char *, int);
void sort_ascending(char *, int);

int main(void){
    int arr*, size;
    pirntf("input size array: ");
    scanf(" %5d");
    arr = malloc(size * sizeof(int));
    printf("Input array elements: ");
    for(int i = 0; i < size; i++){
        scanf(" %d");
    }
    sort_descending(arr, size);
    sort_ascending(arr, size);
    free(arr);

    return 0;
}

void sort_descending(char *arr, int size){
    int position_counter, max;
    for(int i = 0; i < size; i++){

    }
}
