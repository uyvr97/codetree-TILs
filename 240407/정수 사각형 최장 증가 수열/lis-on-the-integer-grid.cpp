#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[501][501], dp[501][501];
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

bool InRange(int x, int y){
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

void count(int x, int y){ //dfs
    if(dp[x][y] > 1) return;
    for(int i = 0; i < 4; i++){
        int cnt = 1;
        int nx = x + dx[i], ny = y + dy[i];
        if(InRange(nx, ny) && arr[nx][ny] > arr[x][y]){ //dp[nx][ny]가 0이 아니면 종료, 0이면 재귀 
            count(nx, ny);
            cnt += dp[nx][ny];
        }
        dp[x][y] = max(cnt, dp[x][y]);
    }
    return;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
            dp[i][j] = 1;
        }
    }

    int rel = 0;
   for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            count(i, j);
            rel = max(rel, dp[i][j]);
        }
   }

   cout << rel;
    return 0;
}