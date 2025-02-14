#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I wanna test my demonstration on the inverse of a square matrix
void printm(long double **m);

int main(void){
    long double **a = malloc(sizeof(long double) * 10);
    long double **b = malloc(sizeof(long double) * 10);
    long double c;

    for(int i = 0; i < 10; i++){
        a[i] = malloc(sizeof(long double) * 10);
        b[i] = malloc(sizeof(long double) * 10);
    }

    for(int i = 0; i < 10; i++){
        for(int k = 0; k < 10; k++){
            a[i][k] = rand() % 100;
            if(i == k)
                b[i][i] = 1 / a[i][i];
            else 
                b[i][k] = 0;

        }
    }
    printf("A:\n");
    printm(a);
    printf("B:\n");
    printm(b);

    printf("\n\n");
    for(int s = 0; s < 10; s++){
        for(int i = 0; i < 10; i++){
            for(int k = 0; k < 10; k++){
                c += a[s][k] * b[k][i];
            }
            printf("%Lf ", c);
        }
        printf("\n");
    }


    return 0;
}

void printm(long double **m){
    for(int i = 0; i < 10; i++){
        for(int k = 0; k < 10; k++){
            printf("%Lf ", m[i][k]);
        }
        printf("\n");
    }
}
