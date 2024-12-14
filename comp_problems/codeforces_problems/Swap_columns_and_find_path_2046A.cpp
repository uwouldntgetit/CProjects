#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solution();
long func(vector<vector<long>>, long);

int main(){
    int t;

    cin >> t;

    while(t-- > 0){
        solution();
    }
}



void solution(){
    long n, m, res, p;
    m = LONG_MIN;
    p = res = 0;
    cin >> n;
    vector<vector<long>> arr(2, vector<long>(n));

    for(int i = 0; i < 2; i++){
        for(int k = 0; k < n; k++){
            cin >> arr[i][k];
        }
    }

    for(int i = 0; i < n; i++){
        // why is this the wrong algorithm
        if(arr[1][i] + arr[0][i] > m){
            m = arr[0][i] + arr[1][i];
            p = i;
        }

        if(arr[1][i] > arr[0][i])
            res += arr[1][i];
        else 
            res += arr[0][i];

    }

    m = func(arr, p);
        
    for(int i = 0; i < n; i++){
        if(arr[0][i] > m && arr[1][i] > m){
            p = i;
            m = func(arr, p);
        }

    }

    if(arr[1][p] > arr[0][p])
        res += arr[0][p];
    else 
        res += arr[1][p];


    cout << res << endl;
}
// I've never really understood the beauty of competitive programming
// But i Undersand it now


long func(vector<vector<long>> arr, long p){
    long m;
    if(arr[0][p] > arr[1][p])
        m = arr[1][p];
    else
        m = arr[0][p];

    return m;
} 

