//2026.04.11 success
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int a;
            cin >> a;
            v[i][j] = a;
        }
    }

    queue<pair<int, int>> q;
    int total = 0;
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == 1) {
                v[i][j] = 0;
                int cnt = 1;
                q.push(make_pair(i,j));
                
                while (!q.empty()) {
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    
                    if (row < n-1 && v[row+1][col] == 1) {
                        cnt++;
                        v[row+1][col] = 0;
                        q.push(make_pair(row+1, col));
                    } 
                    if (row > 0 && v[row-1][col] == 1) {
                        cnt++;
                        v[row-1][col] = 0;
                        q.push(make_pair(row-1, col));
                    } 
                    if (col < m-1 && v[row][col+1] == 1) {
                        cnt++;
                        v[row][col+1] = 0;
                        q.push(make_pair(row, col+1));
                    } 
                    if (col > 0 && v[row][col-1] == 1) {
                        cnt++;
                        v[row][col-1] = 0;
                        q.push(make_pair(row, col-1));
                    } 
                }

                total += 1;
                ans = max(ans, cnt);
            }
        }
    }

    cout << total << "\n" << ans;
}