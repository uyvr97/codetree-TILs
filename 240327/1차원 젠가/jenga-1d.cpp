#include <iostream>
#include<cstring>
using namespace std;

int arr[101][101];
int n, cnt;
int s[2], e[2];


void out(int s, int e){
    for(int i = s; i <= e; i++){
        arr[0][i] = 0;
        cnt++;
    }
}

void rel(){
    int tmp = n;
    for(int i = n; i > 0; i--){
        if(arr[0][i] != 0){
            arr[1][tmp] = arr[0][i];
            tmp--;
        }
    }
    for(int i = 1; i <= n; i++) arr[0][i] = arr[1][i];
}

int main() {
    cin >> n;
    for(int i=1; i <= n; i++)cin >> arr[0][i];

    for(int i = 0 ; i < 2 ;i++){
        cin >> s[i] >> e[i];
    }

    for(int i = 0 ;i < 2; i++){
        out(cnt + s[i], cnt + e[i]);
        memset(arr[1], sizeof(arr[1]), 0);
        rel();
    }        
    
    cout << n - cnt << "\n";
    if(n - cnt != 0){
        for(int i = cnt + 1; i <= n; i++)cout << arr[1][i]<<"\n";
    }
    
    return 0;
}