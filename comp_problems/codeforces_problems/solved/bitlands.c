#include <stdio.h>
#include <string.h>

int main(void){
    int n;
    // number of statements in the program
    int result = 0;
    char string[4];
    
    scanf("%d", &n);
    if(n < 1 || n > 150) return 0;

    for(int i = 0; i < n; i++){
        scanf(" %3[^\n]", string);
        if(strcmp(string, "X++") == 0 || strcmp(string, "++X") == 0) result++;
        if(strcmp(string, "X--") == 0 || strcmp(string, "--X") == 0) result--;
    }

    printf("%d", result);


    return 0;
}
