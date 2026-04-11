//2026.04.11 success
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp(vector<vector<int>> v, vector<vector<int>> memo, int n) {
    for (int i=1; i<n; i++) {
        memo[i][0] = min(memo[i-1][1], memo[i-1][2]) + v[i][0];
        memo[i][1] = min(memo[i-1][0], memo[i-1][2]) + v[i][1];
        memo[i][2] = min(memo[i-1][0], memo[i-1][1]) + v[i][2];
    }

    return min({memo[n-1][0], memo[n-1][1], memo[n-1][2]});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<vector<int>> v(n, vector<int>(3, 0));
    for (int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[i][0] = a;
        v[i][1] = b;
        v[i][2] = c;
    }

    vector<vector<int>> memo(n, vector<int>(3, 0));
    memo[0][0] = v[0][0];
    memo[0][1] = v[0][1];
    memo[0][2] = v[0][2];

    cout << dp(v, memo, n);
}