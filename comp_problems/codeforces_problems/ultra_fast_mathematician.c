#include <stdio.h>
#include <string.h>

void get_string(char *string, int length);

int main(void){
    char string1[101], string2[101], final_string[101];
    int i;

    get_string(string1, 100);
    get_string(string2, 100);

    for(i = 0;string1[i] != 0; i++){
        if(string1[i] == string2[i])
            final_string[i] = '0';
        else
            final_string[i] = '1';
    }
    final_string[i] = 0;

    for(int i = 0; final_string[i] != 0; i++)
        printf("%c", final_string[i]);
    return 0;
}

void get_string(char *string, int length){
    if(fgets(string, length, stdin))
        string[strcspn(string, "\n")] = 0;
}
