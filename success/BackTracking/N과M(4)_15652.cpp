#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void back(int n, int m, int depth, vector<int>& v) {
    if (depth == m) {
        for (int i=0; i<m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=1; i<=n; i++) {
        if (v[depth-1] > i) continue;
        v[depth] = i;
        back(n,m, depth+1, v); 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    vector<int> v(n+1, -1);
    back(n,m,0,v);
}