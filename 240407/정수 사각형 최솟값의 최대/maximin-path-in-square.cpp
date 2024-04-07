#include <iostream>
using namespace std;

int n;
int arr[101][101], dp[101][101];

void Initialize(){
    dp[1][1] = arr[1][1];
    for(int j = 2; j <= n; j++){
        dp[1][j] = min(dp[1][j-1], arr[1][j]);
        dp[j][1] = min(dp[j-1][1], arr[j][1]);
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];
    }
    
    Initialize();
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            dp[i][j] = max(min(arr[i][j], dp[i][j-1]), min(arr[i][j], dp[i-1][j]));
        }
    }

    cout << dp[n][n];
    return 0;
}