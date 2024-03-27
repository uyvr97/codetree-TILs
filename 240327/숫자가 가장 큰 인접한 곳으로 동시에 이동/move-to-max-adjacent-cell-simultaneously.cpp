#include <iostream>
using namespace std;

int n, m, t; // t := 시뮬레이션이 진행되는 시간
int arr[21][21]; //arr[][] := 격자에 적힌 수의 정보를 담는 배열
int cnt[21][21]; //cnt[][] := 각 격자에 존재하는 구슬의 개수를 담는 배열
int tmp[21][21]; //temp[][] := 구슬이 이동한 결과를 담는 cnt 배열의 복사본

// 입력 받는 함수
void input(){
    // 격자와 구슬의 위치 입력받기
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        int r, c;
        cin >> r >> c;
        cnt[r][c] = 1; // r행 c열에 구슬이 1개 존재
    }
}

bool InRange(int i, int j){
    return (i > 0 && i <= n && j > 0 && j <= n);
}

// i행 j열의 구슬을 이동시켜주는 함수
void Move(int i, int j){
    // 1. 인접한 곳에서 가장 큰 값 결정
    int maxValue = 0, row, col;
    // maxValue := 네 곳 중 가장 큰 값
    // row, col := 가장 큰 값에 존재하는 격자 좌표

    //상하좌우 순서대로 탐색
    int di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, -1, 1};
    for(int d = 0; d < 4; d++){
        int ni = i + di[d], nj = j + dj[d];
        if(InRange(ni, nj) && maxValue < arr[ni][nj]){
            maxValue = arr[ni][nj];
            row = ni;
            col = nj;
        }
    }

    // 2. 해당 위치로 이동
    tmp[row][col] += 1;
}

//각 구슬을 조건에 맞게 이동
void MoveAll(){
    // 1. 1초 뒤에 상황을 저장한 배열을 초기화 하기
    for(int i = 1; i <= n; i++){
        for( int j = 1; j <= n; j++){
            tmp[i][j] = 0;
        }
    }

    // 2. 구슬을 찾아서 이동시키기
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(cnt[i][j] == 1){ // i행 j열에 구슬이 하나 있다
                Move(i,j); // i행 j열의 구슬을 이동시켜주는 함수
            }
        }
    }

    // 3. cnt 배열에 temp 배열 덮어씌우기
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cnt[i][j] = tmp[i][j];
        }
    }
}

// 충돌된 구슬들 삭제하기
void RemoveDuplicationMarbles(){
    for(int i = 1; i <= n ;i++){
        for(int j = 1; j <= n; j++)
            if(cnt[i][j] > 1) cnt[i][j] = 0;
    }
}

// 문제를 해결하는 함수
void process(){
    // t초 동안 시뮬레이션 수행
    while(t--){
        // 1. 각 구슬을 조건에 맞게 이동
        MoveAll();
        // 2. 충돌된 구슬들 삭제하기
        RemoveDuplicationMarbles();

    }

    // 남아있는 구슬 개수 계산
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ans += cnt[i][j];
        }
    }
    cout << ans;
}

int main() {

    input();
    process();
    
    return 0;
}