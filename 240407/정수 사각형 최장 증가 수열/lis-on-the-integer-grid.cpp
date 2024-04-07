#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[501][501], dp[501][501];
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

bool InRange(int x, int y){
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

void count(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = r + dx[i], ny = c + dy[i];
            if(InRange(nx, ny) && arr[nx][ny] > arr[r][c]){
                dp[x][y]++;
                q.push({nx,ny});
                if(dp[nx][ny] != 0){
                    dp[x][y] += dp[nx][ny];
                    return;
                }
            }
        }
    }
    return;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) 
            cin >> arr[i][j];
    }

    int rel = 0;
   for(int i = 1; i <= n; i++){
        for(int j= 1; j <=n; j++){
            count(i,j);
            rel = max(rel, dp[i][j]);
        }
   }

   cout << rel;
    return 0;
}