//2026.04.11 success
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        for (int j=0; j<str.length(); j++) {
            v[i][j] = str[j]-'0';
        } 
    }

    queue<pair<int, int>> q;
    int total = 0;
    vector<int> memo;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
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
                    if (col < n-1 && v[row][col+1] == 1) {
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
                memo.push_back(cnt);
            }
        }
    }

    cout << total << "\n";
    sort(memo.begin(), memo.end());
    for (int i : memo) {
        cout << i << "\n";
    }
}