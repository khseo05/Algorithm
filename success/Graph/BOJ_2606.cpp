#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int> v[], vector<bool>& visited, int node, int& cnt) {
    for (int next : v[node]) {
        if (!visited[next]) {
            visited[next] = true;
            cnt++;
            dfs(v, visited, next, cnt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v[101];

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int cnt = 0;
    vector<bool> visited(n+1, false);
    visited[1] = true;
    dfs(v, visited, 1, cnt);
    cout << cnt;
}