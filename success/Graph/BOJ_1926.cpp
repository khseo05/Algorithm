// 그림 개수, 가장 넓은 것의 넓이 출력
// 가로 세로는 연결 대각선은 다른 그림
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>>& v, int& size, int i, int j, int n, int m) {
    v[i][j] = 0; 
    size++;      

    if (j + 1 < m && v[i][j + 1] == 1) dfs(v, size, i, j + 1, n, m);
    if (j - 1 >= 0 && v[i][j - 1] == 1) dfs(v, size, i, j - 1, n, m);
    if (i + 1 < n && v[i + 1][j] == 1) dfs(v, size, i + 1, j, n, m);
    if (i - 1 >= 0 && v[i - 1][j] == 1) dfs(v, size, i - 1, j, n, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int a;
            cin >> a;
            v[i][j] = a;
        }
    }

    int cnt = 0;
    int size = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == 0) continue;
            int maxSize = 0;
            dfs(v, maxSize, i, j, n, m);
            size = max(size, maxSize);
            cnt++;
        }
    } 
    cout << cnt << "\n" << size;
}