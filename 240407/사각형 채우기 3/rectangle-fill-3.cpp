#include <iostream>
using namespace std;

#define MAX 1000000007
int arr[1001];

int main() {
    int n;
    cin >> n;
    arr[1] = 2;
    arr[2] = 7;
    for(int i = 3; i <= n; i++){
        arr[i] = (arr[i-1]*2 + arr[i-2]*3 + 2) % MAX;
    }

    cout << arr[n];
    
    return 0;
}