#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void dfs(vector<int> v[], vector<bool>& visited, int node) {
    visited[node] = true;
    cout << node << " ";

    for (int next : v[node]) {
        if (!visited[next]) {
            dfs(v, visited, next);
        }
    }
}

void bfs(vector<int> v[], vector<bool>& visited, int node) {
    queue<int> q;

    q.push(node);
    visited[node] = false;

    while (!q.empty()) {
        int n = q.front();
        q.pop();
        cout << n << " ";
        for (int next : v[n]) {
            if (visited[next]) {
                visited[next] = false;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m ,k;
    cin >> n >> m >> k;

    vector<int> v[1001];

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
        sort(v[a].begin(), v[a].end());
        sort(v[b].begin(), v[b].end());

    }

    vector<bool> visited(n+1, false);

    dfs(v, visited, k);

    cout << "\n";


    bfs(v, visited, k);
}