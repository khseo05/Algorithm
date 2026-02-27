// 2026-02-22
// 2026-02-27
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp(int n, vector<vector<int>> v, vector<vector<int>> memo) {

    memo[0][0] = v[0][0];
    memo[0][1] = v[0][1];
    memo[0][2] = v[0][2];

    for (int i=1; i<n; i++) {
        memo[i][0] = v[i][0] + min(memo[i-1][1], memo[i-1][2]);
        memo[i][1] = v[i][1] + min(memo[i-1][0], memo[i-1][2]);
        memo[i][2] = v[i][2] + min(memo[i-1][0], memo[i-1][1]);
    }

    return min(memo[n-1][0], min(memo[n-1][1], memo[n-1][2]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(3, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            int a;
            cin >> a;
            v[i][j] = a;
        }
    }

    vector<vector<int>> memo(n, vector<int>(3, 0));
    cout << dp(n, v, memo);
}