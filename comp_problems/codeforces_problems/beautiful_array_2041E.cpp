#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // a is the median and b the mean
    int a, b, c;
    vector<int> arr(3);

    cin >> b >> a;

    c = b * 3;
    c -= a;
    c -= a - 1;

    cout << 3 << endl;
    cout << c << " " << a << " " << a - 1 << endl;

    return 0;
}
