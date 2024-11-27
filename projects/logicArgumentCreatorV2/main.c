#include "header.h"

int main(void){
    int mode = 0, form = 0;
    
    while(mode != 1 && mode != 2){
        printf("Welcome to the Logic Argument Creator V2.0\n choose which mode you want to use:\n1. Print the argument form\n2. Create an argument\n");
        scanf("%d", &mode);
        printf("mode:%d\n", mode);
        getchar();
    }

    while(form < 1 || form > 4){
        printf("Choose an argument form:\n1. modus ponens\n2. modus tollens\n3. specialization\n4. elimination\n");
        scanf("%d", &form);
        getchar();
    }
    generalFunction(mode, form);
    

    return 0;
}

