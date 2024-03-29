#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> v;

void Print(){
    for(int i = 0; i < m; i++)
        cout << v[i] << " ";
    cout << "\n";
}
void select(int cur_num){
    if(cur_num == m){
        Print();
        return;
    }

    int last = 0;
    if(cur_num >= 1){
        last = v[cur_num - 1];
    }

    for(int i = last + 1; i <= n ; i++){
        v.push_back(i);
        select(cur_num + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    select(0);
    return 0;
}