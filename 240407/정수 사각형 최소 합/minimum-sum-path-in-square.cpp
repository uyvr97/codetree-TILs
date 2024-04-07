#include <iostream>
using namespace std;

int n;
int arr[101][101], dp[101][101];

void Initialize(){
    for(int i = 1; i <= n; i++){
        dp[i][n] = dp[i-1][n] + arr[i][n];
    }
    for(int i = n; i >= 1; i--){
        dp[1][i] = dp[1][i+1] + arr[1][i];
    }
}

int main() {
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];
    }

    Initialize();
    for(int i = 2; i <= n; i++){
        for(int j = n-1; j >= 1; j--){
            dp[i][j] = min(dp[i][j+1], dp[i-1][j]) + arr[i][j];
        }
    }

    cout << dp[n][1];

    return 0;
}