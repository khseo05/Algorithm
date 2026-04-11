//2026.04.11 success
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp(vector<vector<int>> memo, vector<vector<int>> v, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                memo[i][j] = memo[i - 1][j] + v[i][j];
            }
            else if (j == i) {
                memo[i][j] = memo[i - 1][j - 1] + v[i][j];
            }
            else {
                memo[i][j] = max(memo[i - 1][j - 1], memo[i - 1][j]) + v[i][j];
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < n; j++) {
        ans = max(ans, memo[n - 1][j]);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> memo(n, vector<int>(n, 0));
    memo[0][0] = v[0][0];

    cout << dp(memo, v, n);
}