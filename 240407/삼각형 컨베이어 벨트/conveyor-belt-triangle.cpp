#include <iostream>
using namespace std;

int n,t;
int arr[600];

void conv(){
    int tmp = arr[n*3-1];
    for(int i = n*3 - 1; i >= 0; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = tmp;
}

int main() {
    cin >> n >> t;
    for(int i = 0; i < n*3; i++)cin >> arr[i];
    for(int i = 0 ; i < t; i++) conv();
    for(int i = 0 ; i < n*3; i++){
        cout << arr[i] <<" ";
        if(i % n == 2)cout << "\n";
    }
    return 0;
}