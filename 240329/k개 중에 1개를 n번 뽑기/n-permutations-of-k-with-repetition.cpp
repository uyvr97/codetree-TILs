#include <iostream>
#include <vector>
using namespace std;

int k,n;
vector<int> v;

void print(){
    for(int i = 0 ; i < n; i++)
        cout << v[i] << " ";
    cout << "\n";
}

void Choose(int cur_num){
    if(cur_num == n){
        print();
        return;
    }

    for(int i = 1; i <= k; i++){
        v.push_back(i);
        Choose(cur_num + 1);
        v.pop_back();
    }
    return;
}


int main() {
    cin >> k >> n;
    Choose(0);
    return 0;
}