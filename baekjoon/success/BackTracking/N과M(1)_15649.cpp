#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void back(vector<bool>& visited, vector<int>& v, int n, int m, int depth) {
    if (depth == m) {
        for (int i=0; i<m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=1; i<=n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        v[depth] = i;
        back(visited, v, n, m, depth+1);
        visited[i] = false; 
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> visited(n+1, false);
    vector<int> v(n+1);

    back(visited, v, n, m, 0);
}