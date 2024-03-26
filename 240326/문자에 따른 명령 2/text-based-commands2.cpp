#include <iostream>
using namespace std;

int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

int main() {
    // 여기에 코드를 작성해주세요.
    string cmd;
    int dir = 2;
    int x = 0, y = 0;
    cin >> cmd;
    for(int i = 0 ;i  < cmd.size();i++){
        if(cmd[i] == 'F'){
            x += dx[dir];
            y += dy[dir];
        }
        else if(cmd[i] == 'L'){
            dir = (dir + 3) % 4;
        }
        else {
            dir = (dir + 1) % 4;
        }
    }
    cout << x << " "<< y;
    return 0;
}