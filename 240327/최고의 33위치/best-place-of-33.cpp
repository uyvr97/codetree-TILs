#include <iostream>
using namespace std;

bool arr[20][20];

int count(int row, int col){
    int rel = 0;
    for(int i = row; i < row + 3; i++){
        for(int j = col; j < col + 3; j++){
            if(arr[i][j]==1)rel++;
        }
    }
    return rel;
}

int main() {
    int n, rel = 0;
    cin >> n;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    for(int i = 0 ; i < n; i++){
       for(int j = 0 ; j < n; j++){
            if((i + 2) >= n || (j + 2) >= n) continue;
            rel = max(rel,count(i,j));
       } 
    }
    cout << rel;
    return 0;
}