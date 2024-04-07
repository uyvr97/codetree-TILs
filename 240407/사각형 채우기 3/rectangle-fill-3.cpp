#include <iostream>
using namespace std;

#define MAX 1000000007
long long arr[1001];

int main() {
    int n;
    cin >> n;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 7;
    for(int i = 3; i <= n; i++){
        arr[i] = (arr[i-1]*2 + arr[i-2]*3) % MAX;
        for(int j = i-3; j >= 0; j--){
            arr[i] = (arr[i] + arr[j]*2) % MAX;
        }
    }

    cout << arr[n];
    
    return 0;
}