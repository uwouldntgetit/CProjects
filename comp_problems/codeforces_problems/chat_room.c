#include <stdio.h>
#include <string.h>

int main(void) {
        char s[101];
        char str[] = "hello";
        int pos = 0, res = 0;

        scanf("%s", s);

        // starts from the first letter berfore 'e' which should be an 'h'
        for(int i = 0; i < strlen(s); i++){
            if(s[i] == str[pos]){
            res++;
            pos++;
            }

            if(res == 5) break;
        }

        printf("%s\n", res == 5 ? "YES" : "NO");
}
