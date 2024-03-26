#include <iostream>
using namespace std;

int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int x = 0, y = 0;
    int idx, dis;
    for(int i  =  0 ;i < n; i++){
        char s;
        cin >> s;
        if(s == 'N'){
            idx = 2;
        }
        else if(s =='S'){
            idx = 3;
        }
        else if(s =='E'){
            idx = 0;
        }
        else
            idx = 1;
        cin >> dis;
        x += dx[idx]*dis;   
        y += dy[idx]*dis;
    }

    cout <<x << " "<<y;

    return 0;
}