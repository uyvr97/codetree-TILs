#include <iostream>
using namespace std;

int arr[101][101], rel[101][101];
int n;

void Initialize(){  
    rel[1][1] = arr[1][1];
    for(int i = 2; i <= n; i++) {
        rel[1][i] = rel[1][i-1] + arr[1][i];
        rel[i][1] = rel[i-1][1] + arr[i][1];
    }

}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= n; j++)cin >> arr[i][j];
    }

    Initialize();

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            rel[i][j] = max(rel[i-1][j], rel[i][j-1]) + arr[i][j];
        }
    }

    cout << rel[n][n];

    return 0;
}