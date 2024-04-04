#include <iostream>
using namespace std;

int arr[1001];

int main() {
    int n;
    cin >> n;
    arr[2] = 1;
    arr[3] = 1;
    for(int i = 4; i <= n; i++){
        arr[i] = (arr[i-2] + arr[i-3]) % 10007;
    }

    cout << arr[n];
    return 0;
}