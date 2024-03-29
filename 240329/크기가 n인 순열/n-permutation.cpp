#include <iostream>
#include <vector>
using namespace std;

int n,m;
bool visit[9];
vector<int> v;

void Print(){
    for(int i=0; i<n; i++)
        cout << v[i] << " ";
    cout << "\n";
}

bool IsUsed(int num){
    return visit[num];
}

void select(int cur_num){
    if(cur_num == n + 1){
        Print();
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!IsUsed(i)){
            v.push_back(i);
            visit[i] = 1;
            select(cur_num + 1);
            v.pop_back();
            visit[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    select(1);
    return 0;
}