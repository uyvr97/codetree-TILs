#include <iostream>
using namespace std;

int n, r, c;
int arr[201][201], tmp[201][201]; 
// tmp := 중력이 적용된 후의 격자 상태

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j =1; j <= n; j++)
            cin >> arr[i][j];
    }
    cin >> r >> c;
}

bool InRange(int r, int c){
    return (r > 0 && r <= n && c > 0 && c <= n);
}

void bomb(){
    // 폭탄의 범위만큼 상하좌우를 0으로 변경하기
    int size = arr[r][c]; // size := 폭탄의 범위
    int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};

    arr[r][c] = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 1 ; j < size; j++){
            int nr = r + dr[i]*j, nc = c + dc[i]*j;
            if(InRange(nr, nc))
                arr[nr][nc] = 0;
        }
    }
}

void fall(){
    for(int col = 1; col <= n; col++){
        int TmpRow = n;
        for(int row = n; row > 0; row--){
            if(arr[row][col] != 0){
                tmp[TmpRow][col] = arr[row][col];
                TmpRow--;
            }
        }
    }
}

void proc(){
    // 1. 주어진 위치에서 폭탄 터뜨리기
    bomb();
    // 2. 중력 작용
    fall();
    // 3. 결과 출력
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << tmp[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    input();
    proc();
    return 0;
}