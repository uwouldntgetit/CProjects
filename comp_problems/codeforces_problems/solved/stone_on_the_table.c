#include <stdio.h>
#include <string.h>

int main(void){
    char string[51];
    int result = 0, number_elems, length;

    scanf("%3d", &number_elems);
    if(number_elems < 1 || number_elems > 50) return 0;
    scanf(" %50[^\n]", string);
    length = strlen(string);
    if(length > number_elems) return 0;

    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == string[i + 1]){
            result++;
        }
    }

    printf("%d", result);

    return 0;
}
