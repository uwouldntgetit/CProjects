#include <stdio.h>

int main(void){
    int t, b1, b2, b3, maxCheck, maxCarry, check, carry;
    scanf("%d", &t);

    while(t--){
        scanf("%d%d%d%d%d", &b1, &b2, &b3, &maxCheck, &maxCarry);
        carry = -1;

        if(maxCarry >= b1) carry = b1;
        if(maxCarry >= b2 && b2 > carry) carry = b2;
        if(maxCarry >= b3 && b3 > carry) carry = b3;
        if(carry == -1){
            printf("NO\n");
            continue;
        }

        check = b1 + b2 + b3 - carry;

        if(check <= maxCheck)
            printf("YES\n");
        else
            printf("NO\n");

    }
}
