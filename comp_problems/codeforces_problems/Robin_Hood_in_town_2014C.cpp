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
    long n, x, c;
    double avg;

    cin >> n;
    x = c = 0;
    long arr[n];

    for(long i = 0; i < n; i++){
        cin >> arr[i];
        avg += arr[i];
    }

    avg /= n;
    for(int i = 0; i < n; i++){
        if(arr[i] < avg) c++;
    }
    
    if(c > ((double)n / 2))
        cout << "Robin appears" << endl;
    else 
        cout << "Robin doesn't appear" << endl;
    //cout << avg << endl;
    //cout << "count: " << c << endl;

}
