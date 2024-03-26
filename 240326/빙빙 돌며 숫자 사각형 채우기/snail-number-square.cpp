#include <iostream>
using namespace std;

int n,m;
int arr[100][100];
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

bool InRange(int x, int y){
    return (x >=0 && x < n && y >= 0 && y < m);
}

void input(){
    cin >> n >> m;
}

void proc(){
    int x = 0, y = 0;
    int idx = 1, dir = 0;

    while(idx <= n*m){
        arr[x][y] = idx++;

        int nx = x + dx[dir], ny = y + dy[dir];
        if(!InRange(nx, ny) || arr[nx][ny] != 0)
            dir = (dir + 1) % 4;
        x += dx[dir];
        y += dy[dir];

    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++)cout << arr[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    input();
    proc();
    return 0;
}