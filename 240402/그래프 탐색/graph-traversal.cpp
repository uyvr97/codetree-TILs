#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
bool visit[1001];
int cnt = 0;

void DFS(int ver){
    visit[ver] = 1;
    for(int i = 0; i < v[ver].size(); i++){
        int cur = v[ver][i];
        if(!visit[cur]){
            DFS(cur);
            cnt++;
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    v.resize(n+1);
    for(int i = 0 ; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1);
    cout << cnt;

    return 0;
}