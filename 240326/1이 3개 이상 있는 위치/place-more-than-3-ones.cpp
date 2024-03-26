#include <iostream>
using namespace std;

bool map[100][100];
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
int n, rel;

bool InRange(int x, int y){
    return (x >=0 && x < n && y >= 0 && y < n );
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0; i< n;i++){
        for(int j = 0;j < n;j++)
            cin >> map[i][j];
    }

    for(int i=0;i <n;i++){
        for(int j =0; j<n;j++){
            int cnt = 0;
            for(int k = 0 ; k < 4; k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(InRange(nx, ny) && map[nx][ny]) cnt++;
            }
            if(cnt >= 3)rel++;
        }
    }

    cout << rel;

    return 0;
}