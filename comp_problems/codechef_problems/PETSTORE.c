#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void){
    int t, num, *array, count, result;

    assert(1 == scanf("%d", &t));

    for(int i = 0; i < t; i++){
        assert(1 == scanf("%d", &num));
        result = 1;
        array = malloc(sizeof(int) * num);

        for(int k = 0; k < num; k++){
            assert(1 == scanf("%d", array + k));
        }

        if(num % 2 == 1){
            printf("NO\n");
            continue;
        }

        for(int k = 0; k < 101; k++){
            count = 0;
            for(int h = 0; h < num; h++){
                if(array[h] == k)
                    count++;
            }

            if(count % 2 != 0){
                result = 0;
                break;
            }
        }
        
        if(result == 0)
            printf("NO\n");
        else
            printf("YES\n");

    }
}
