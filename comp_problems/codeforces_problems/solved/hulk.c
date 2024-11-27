#include <stdio.h>

int main(void){
    int layers;
    char hate[] = "I hate";
    char love[] = "I love";

    scanf("%d", &layers);

    for(int i = 0; i < layers; i++){
        if(i % 2 == 0) printf("%s", hate);
        else printf("%s", love);

        if(i != layers - 1) printf(" that ");
        else printf(" it\n");
    }
}
