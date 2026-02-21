// 10 X 8 | 배추가 심어져 있는 위치의 개수: 17
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& v, int i, int j, int col, int row) {
    v[i][j] = 0;
    if (j+1 < row && v[i][j+1] == 1) dfs(v, i, j+1, col, row);
    if (j-1 >= 0 && v[i][j-1] == 1) dfs(v, i, j-1, col, row);
    if (i+1 < col && v[i+1][j] == 1) dfs(v, i+1, j, col, row);
    if (i-1 >= 0 && v[i-1][j] == 1) dfs(v, i-1, j, col, row);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, row, col, k;
    cin >> T;

    for (int i=0; i<T; i++) {
        cin >> row >> col >> k;

        vector<vector<int>> v(col, vector<int>(row, 0));
        for (int i=0; i<k; i++) {
            int a, b;
            cin >> a >> b;
            v[b][a] = 1;
        }
        int cnt=0;
        for (int i=0; i<col; i++) {
            for (int j=0; j<row; j++) {
                if (v[i][j] == 0) continue;
                cnt++;
                dfs(v, i, j, col, row);
            }
        }

        cout << cnt << "\n";
    }
}