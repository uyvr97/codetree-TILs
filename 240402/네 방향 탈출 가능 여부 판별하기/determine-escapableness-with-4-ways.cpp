#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int arr[100][100], visit[100][100];
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
queue<pair<int,int>> q;

bool InRange(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void BFS(){
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(!InRange(nx, ny))continue;
            if(arr[nx][ny] == 1 && visit[nx][ny] == false){
                visit[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}


int main() {
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m ;j++){
            cin >> arr[i][j];
        }
    }

    q.push({0,0});
    visit[0][0] = 1;
    BFS();

    if(visit[n-1][m-1])cout << 1;
    else cout << 0;

    return 0;
}