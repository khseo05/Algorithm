#include <iostream>
#include <vector>
using namespace std;

void graph(vector<int> v[], vector<bool>& visited, int n, int m, int node) {
    visited[node] = true;
    for (int next : v[node]) {
        if (!visited[next]) {
            graph(v, visited, n, m, next);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v[1001];

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<bool> visited(n+1, false);
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            graph(v, visited, n, m, i);
            cnt++;
        }
    }

    cout << cnt;
}