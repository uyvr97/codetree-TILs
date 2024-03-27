#include <iostream>
using namespace std;

int arr[101][101];
int n, cnt;
int s[2], e[2];


void out(int s, int e, int idx){
    for(int i = s; i <= e; i++){
        arr[idx][i] = 0;
        cnt--;
    }
}

void rel(int idx){
    int tmp = n;
    for(int i = n; i > 0; i--){
        if(arr[idx][i] != 0){
            arr[1-idx][tmp] = arr[idx][i];
            tmp--;
        }
    }
}

int main() {
    cin >> n;
    for(int i=1; i <= n; i++)cin >> arr[0][i];

    for(int i = 0 ; i < 2 ;i++){
        cin >> s[i] >> e[i];
    }

    cnt = n;
    for(int i = 0 ;i < 2; i++){
        out(s[i],e[i],i);
        rel(i);
    }        
    
    cout << cnt << "\n";
    if(cnt != 0){
        for(int i = n - cnt + 1; i <= n; i++)cout << arr[1][i]<<"\n";
    }
    
    return 0;
}