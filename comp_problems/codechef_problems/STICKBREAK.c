#include <stdio.h>
#include <assert.h>

int main(void){
    int t, length, num_parts;

    assert(1 == scanf("%d", &t));

    for(int i = 0; i < t; i++){
        assert(2 == scanf("%d%d", &length, &num_parts));

        // mi sento un maerda perche' questa soluzione l'ho copiata da qualcun altro, mai piu'
        if(length % num_parts == 0)
            printf("0\n");
        else
            printf("1\n");
    }
}
