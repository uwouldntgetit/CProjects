/*Theatre Square in the capital city of Berland has a rectangular shape with the size n × m meters. On the occasion of the city's anniversary,
  a decision was taken to pave the Square with square granite flagstones. Each flagstone is of the size a × a.

What is the least number of flagstones needed to pave the Square? It's allowed to cover the surface larger than the Theatre Square, but the Square has to be covered.
It's not allowed to break the flagstones. The sides of flagstones should be parallel to the sides of the Square.

Input
The input contains three positive integer numbers in the first line: n,  m and a (1 ≤  n, m, a ≤ 10^9).

Output
Write the needed number of flagstones.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
    long long int square_x, square_y, flagstone_side;
    long long int x_diff, y_diff, result;

    scanf("%lld%lld%lld", &square_x, &square_y, &flagstone_side);

    x_diff = square_x / flagstone_side;
    y_diff = square_y / flagstone_side;

    if(square_x % flagstone_side != 0) x_diff++;
    if(square_y % flagstone_side != 0) y_diff++;

    result = x_diff * y_diff;

    printf("%lld", result);


    return 0;
}
