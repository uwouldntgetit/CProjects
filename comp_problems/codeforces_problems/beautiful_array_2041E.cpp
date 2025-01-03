#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// devo fare stare a in mezzo ad un sort
// [a + c + (a + k)] / 3 = b
// aha! fun

int main(){
    // a is the median and b the mean
    int a, b, c, k;
    vector<int> arr(3);

    cin >> b >> a;
    k = 1;

    // a is median
    c = b * 3;
    c -= 2 * a;
    // c -= a + k;


    cout << 3 << endl;
    cout << c << " " << a << " " << a << endl;

    return 0;
}

