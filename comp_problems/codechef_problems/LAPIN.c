#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void delete(char *str, int n);

int main(void){
    int times, check, result;
    char *string, *str1, *str2;
    string = "";
    assert(scanf("%d", &times) == 1);

    for(int i = 0; i < times; i++){
        string = malloc(sizeof(char) * 1001);
        assert(scanf("%s", string) == 1);
        // printf("length: %ld\n", strlen(string));
        str1 = malloc(((strlen(string) / 2) + 1) * sizeof(char));
        str2 = malloc(((strlen(string) / 2) + 1) * sizeof(char));
        result = 1;
        check = 0;

        for(int k = 0; k < strlen(string) / 2; k++){
            str1[k] = string[k];
            str2[k] = string[strlen(string) - (k + 1)];
        }
        str1[strlen(string) / 2] = '\0';
        str2[strlen(string) / 2] = '\0';

        // printf("str1: %s\nstr2: %s\n", str1, str2);
        // printf("str1:%ld\nstr2:%ld\n", strlen(str1), strlen(str2));

        for(int k = 0; k < strlen(string) / 2; k++){
            for(int h = 0; h < strlen(string) / 2; h++){
                if(str1[k] == str2[h] && str1[k] != '\0'){
                    delete(str2, h);
                    check++;
                    break;
                }
            }
        }
        if(check != strlen(string) / 2)
            result = 0;

        // printf("check: %d\nstrlen(string) / 2: %ld\n", check, strlen(string) / 2);

        if(result == 0)
            printf("NO\n");
        else
            printf("YES\n");

        free(str1);
        free(str2);
        free(string);
    }
}

void delete(char *str, int n){
    for(int i = n;str[i] != '\0'; i++){
        str[i] = str[i + 1];
    }
}
