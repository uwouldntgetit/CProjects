#include <stdio.h>
#include <stdlib.h>

int main(void){
    char *string, *result;
    int num_cases, str_len;

    scanf("%d", &num_cases);
    getchar();

    for(int i = 0; i < num_cases; i++){
        scanf("%d", &str_len);
        getchar();

        string = malloc((str_len + 1) * sizeof(char));
        result = malloc((str_len + 1) * sizeof(char));
        scanf("%s", string);

        for(int j = 0; string[j] != 0; j++){
            switch(string[j]){
                case 'A':
                    result[j] = 'T';
                    break;
                case 'T':
                    result[j] = 'A';
                    break;
                case 'G':
                    result[j] = 'C';
                    break;
                case 'C':
                    result[j] = 'G';
                    break;
        }

        printf("%s\n", result);
        free(result);
        free(string);
    }
    return 0;
}
