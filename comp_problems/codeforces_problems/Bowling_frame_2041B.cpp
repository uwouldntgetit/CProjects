#include <iostream>

using namespace std;

void solution();

int main(){
    int t;
    cin >> t;

    while(t-- > 0){
        solution();
    }
    return 0;
}

void solution(){
    long a, b, c;
    cin >> a >> b;

    a += b;
    c = 0;

    for(int i = 0; i <= a; i++){
        a -= i;
        c++;
    }
    c--;

    cout << c << endl;

}
