#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int memo(int n, vector<vector<int>>& v, vector<vector<int>>& memo) {
    for (int i=1; i<n; i++) {
        memo[i][0] = v[i][0] + min(memo[i-1][1], memo[i-1][2]);
        memo[i][1] = v[i][1] + min(memo[i-1][0], memo[i-1][2]);
        memo[i][2] = v[i][2] + min(memo[i-1][0], memo[i-1][1]);
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(3,0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            int a;
            cin >> a;
            v[i][j] = a;
        }
    }

    vector<vector<int>> memo(n, vector<int>(3,-1));
    memo[0][0] = v[0][0];
    memo[0][1] = v[0][1];
    memo[0][2] = v[0][2];

    memo(n, v, memo);
    cout << min({memo[n-1][0], memo[n-1][1], memo[n-1][2]});
}