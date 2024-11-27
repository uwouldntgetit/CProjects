#include <stdio.h>

int main(void){
    int times, shelves, books, capacity, result;

    scanf("%d", &times);
    getchar();

    for(int i = 0; i < times; i++){
        result = 0;
        scanf("%d%d%d", &shelves, &books, &capacity);
        getchar();

        result += books / capacity;

        if(books % capacity != 0)
            result++;

        result *= shelves;


        printf("%d\n", result);
    }
}
