//2026.03.07 fail
//2026.03.12 clear
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<bool>& visited, vector<int> v[], int node) {
    visited[1] = true;
    for (int next : v[node]) {
        if (!visited[next]) {
            visited[next] = true;
            dfs(visited, v, next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v[n+1];

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int cnt = 0;
    vector<bool> visited(n+1, false);
    
    visited[1] = true;
    dfs(visited, v, 1);
    for (int i=2; i<=n; i++) {
        if (visited[i]) {
            cnt++;
        }
    }

    cout << cnt;
}