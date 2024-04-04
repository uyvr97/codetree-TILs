#include <iostream>
using namespace std;

int arr[50];

int main() {
    int n;
    arr[0] = 0;
    arr[1] = 1;

    cin >> n;
    for(int i = 2; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout << arr[n];

    return 0;
}