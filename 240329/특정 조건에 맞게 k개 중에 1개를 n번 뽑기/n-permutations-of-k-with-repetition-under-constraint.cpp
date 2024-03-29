#include <iostream>
#include <vector>
using namespace std;

int k,n;
vector<int> v;

void Print(){
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << "\n";
}

void Choose(int cur_num){
    if(cur_num == n){
        Print();
        return;
    }

    for(int i = 1; i <= k; i++){
        if(cur_num >= 2 && v[cur_num - 1] == i && v[cur_num - 2] == i)
            continue;
        v.push_back(i);
        Choose(cur_num + 1);
        v.pop_back();
    }
}

int main() {
    cin >> k >> n;
    Choose(0);
    return 0;
}