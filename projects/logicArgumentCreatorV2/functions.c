// i'm writing the second version of a logical argument creator, a pretty cool idea if i were to say so myself, even if not so useful
// the program will first ask the user which argument form it wants to create, then it will ask him to input the statements needed, and then it'll output the finished argument
// the argument forms used are in order: modus ponens, modus tollens, specialization, elimination

#include "header.h"

void getString(char *string, int length){
    if(fgets(string, length, stdin)){
        *(string + strcspn(string, "\n")) = 0;
    }
}

// general function that centralizes the call of all the other ones
void generalFunction(int mode, int form){
    if(mode == 1){
        printArgumentForm(form);
    }
    else{
        char s1[LEN], s2[LEN];
        printf("Insert the first statement: ");
        getString(s1, LEN);
        printf("Insert the second statement: ");
        getString(s2, LEN);

        switch(form){
            case 1:
                printf("if %s then %s\n%s\nTherefore %s\n", s1, s2, s1, s2);
                break;
            case 2:
                printf("if %s then %s\nis false that %s\nTherefore is false that %s\n", s1, s2, s2, s1);
                break;
            case 3:
                specialization(s1, s2);
                break;
            case 4:
                elimination(s1, s2);
                break;
        }
    }
}

void printArgumentForm(int form){
    switch(form){
        // modus ponens
        case 1:
            printf("if P then Q\nP\nTherefore Q\n");
            break;
        // modus tollens
        case 2: 
            printf("if P then Q\n¬Q\nTherefore ¬P\n");
            break;
        // specialization
        case 3:
            printf("P or Q\nP\nTherefore ¬Q\n");
            break;
        // elimination
        case 4:
            printf("P or Q\n¬P\nTherefore Q\n");
            break;
        default:
            printf("U bastard put an illegal number, do it again and i'll find you and stare ominously at u\n");
    }
}


void specialization(char* s1, char* s2){
    int x = 0;
    printf("Choose which statement to specialize in:\n1. first statement\n2. second statement\n");
    while(x != 1 && x != 2){
        scanf("%d", &x);
        getchar();
    }
    if(x == 1)
        printf("%s or %s\n%s\nTherefore %s is a false statement\n", s1, s2, s1, s2);
    else
        printf("%s or %s\n%s\nTherefore %s is a false statement\n", s1, s2, s2, s1);
}

void elimination(char* s1, char* s2){
    int x = 0;
    printf("Choose which statement to eliminate:\n1. first statement\n2. second statement\n");
    while(x != 1 && x != 2){
        scanf("%d", &x);
        getchar();
    }
    if(x == 1)
        printf("%s or %s\n%s is a false statement\nTherefore %s\n", s1, s2, s1, s2);
    else
        printf("%s or %s\n%s is a false statement\nTherefore %s\n", s1, s2, s2, s1);
}
