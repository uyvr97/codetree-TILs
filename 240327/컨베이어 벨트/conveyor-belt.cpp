#include <iostream>
using namespace std;

int arr[400];
int n, t;

void conveyor(){
    int tmp = arr[2*n -1];
    for(int i = 2*n -2 ; i >= 0; i--){
        arr[i+1] = arr[i];
    }
    arr[0]= tmp;
}

int main() {
    cin >> n >> t;
    for(int i = 0 ; i < 2*n; i++)
        cin >> arr[i];

    for(int i = 0 ; i < t; i++)
        conveyor();
    
    for(int i = 0; i < 2*n ; i++){
        cout << arr[i] << " ";
        if(i == n-1) cout << "\n";
    }
    
    return 0;
}