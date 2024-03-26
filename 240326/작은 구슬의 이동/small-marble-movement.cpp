#include <iostream>
using namespace std;

int n,t;
int r, c;
char d;
//위, 오, 왼, 아래
int dx[] = {-1,0,0,1}, dy[] = {0,1,-1,0};

bool InRange(int x, int y){
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

void input(){
    cin >> n >> t;
    cin >> r >> c >> d;
}

void proc(){
    int dir;
    if(d == 'U') dir = 0;
    else if(d == 'D') dir = 3;
    else if(d == 'R') dir = 1;
    else dir = 2;

    while(t--){

        int nr = r + dx[dir], nc = c + dy[dir];
        if(!InRange(nr,nc)) {
            dir = (3 - dir);
            continue;
        }
        r += dx[dir];
        c += dy[dir];
    }

    cout << r << " "<< c;
}

int main() {
    // 여기에 코드를 작성해주세요.
    input();
    proc();
    return 0;
}