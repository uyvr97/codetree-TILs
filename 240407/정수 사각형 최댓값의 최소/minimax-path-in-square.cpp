#include <iostream>
using namespace std;

int n;
int arr[101][101], dp[101][101];

void Initialize(){
    for(int i = 1; i <= n; i++){
        dp[1][i] = max(dp[1][i-1], arr[1][i]);
        dp[i][1] = max(dp[i-1][1], arr[i][1]);
    }
}

int main() {    

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++)cin >> arr[i][j];
    }

    Initialize();
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            dp[i][j] = min(max(dp[i][j-1], arr[i][j]), max(dp[i-1][j],arr[i][j]));
        }
    }
    cout << dp[n][n];
    return 0;
}