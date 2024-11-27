#include <stdio.h>

int main(void){
    int t, p, n, temp, hard, cake;

    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d%d", &n, &p);
        hard = cake = 0;
        /* the bitch didn't care about my observation and simply wanted me to be stupid about its incorrectedness and not care about parity
        // it gets rid of parity, if odd it becomes even and is not truncated, if even it's truncated but it doesn't change anything
        p++;
        */

        while(n > 0){
            scanf("%d", &temp);

            if(temp >= (p / 2))
                cake++;
            if(temp <= (p / 10))
                hard++;

            n--;
        } 

        if(hard >= 2 && cake >= 1)
            printf("yes\n");
        else
            printf("no\n");
        
    }
}
