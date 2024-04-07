#include <iostream>
using namespace std;

int dx[] = {0,1,-1,0}, dy[]={-1,0,0,1};

int main() {
    int n, time = 0;
    int x = 0, y = 0;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        char dir;
        int idx,dis;
        cin >> dir >> dis;
        if(dir == 'W'){
            idx = 0;
        }
        else if(dir == 'S'){
            idx = 1;
        }
        else if(dir == 'N'){
            idx = 2;
        }
        else {
            idx = 3;
        }
        for(int j = 0; j < dis; j++){
            x += dx[idx];
            y += dy[idx];
            time++;
            if(x == 0 && y == 0){
                cout << time;
                return 0;
            }
        }
    }
    cout << -1;
    
    return 0;
}