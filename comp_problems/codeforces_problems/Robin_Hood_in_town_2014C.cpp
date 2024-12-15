#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
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
    long long n, x, c;
    long double avg, p;

    cin >> n;
    x = c = p = 0;
    avg = 0;
    vector<long> arr(n);


    for(long i = 0; i < n; i++){
        cin >> arr[i];
        avg += arr[i];
    }

    if(n < 3){
        cout << -1 << endl;
        return;
    }

    // descending
    // for(int i = 0; i < n; i++){
    //     for(int k = 0; k < n; k++){
    //         if(arr[i] > arr[k]){
    //             long h = arr[i];
    //             arr[i] = arr[k];
    //             arr[k] = h;
    //         }
    //     }
    // }
    
    sort(arr.begin(), arr.end(), greater<>());

    avg /= n;
    for(long i = n - 1; i >= 0; i--){
        if(arr[i] < (avg / 2)) c++;
        else break;
    }

    // cout << "c: " << c << endl;
    if(c > (n / 2)){
        // cout << "I'm getting to the source" << endl;
        cout << 0 << endl;
        return;
    }

    
    // I have to make some rich people poorer than avg
    p = arr[(n / 2) - (n % 2 == 0 ? 1 : 0)] - (avg / 2);
    p = (p * n * 2.0) + 1;
    x = p;
    if((p - x) > 0.000001) {
        // cout << "did";
        x++;
    }


    /*cout << fixed <<  setprecision(15) << p << endl;*/
    cout << x << endl;
}

// the algorithm works well, but there's some problem with input
