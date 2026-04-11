#include <iostream>
#include <vector>
using namespace std;

void graph(vector<vector<int>>& v, int a, int b, int i, int j) {
    v[i][j] = 0;
    if (i-1 >= 0 && v[i-1][j] == 1) graph(v, a, b, i-1, j);
    if (i+1 < a && v[i+1][j] == 1) graph(v, a, b, i+1, j);
    if (j-1 >= 0 && v[i][j-1] == 1) graph(v, a, b, i, j-1);
    if (j+1 < b && v[i][j+1] == 1) graph(v, a, b, i, j+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        vector<vector<int>> v(a, vector<int>(b, 0));
        for (int j=0; j<c; j++) {
            int d, e;
            cin >> d >> e;
            v[d][e] = 1;
        }

        int cnt = 0;
        for (int i=0; i<a; i++) {
            for (int j=0; j<b; j++) {
                if (v[i][j] == 0) continue;
                cnt++;
                graph(v, a, b, i, j);
            }
        }
        cout << cnt << "\n";
    }
}