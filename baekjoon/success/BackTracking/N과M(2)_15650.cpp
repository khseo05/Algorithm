#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void back(int n, int m, int start, int depth, vector<int>& v) {
    if (depth == m) {
        for (int i=0; i<m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=start; i<=n; i++) {
        v[depth] = i;
        back(n, m , i+1, depth+1, v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n+1);
    back(n, m, 1, 0, v);
}