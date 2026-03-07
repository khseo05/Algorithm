// 탑 다운, 바텀 업 둘다 해보기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int n, vector<int>& memo) {
    if (n==1) return 0;
    if (memo[n] != -1) return memo[n];

    int cost = dfs(n-1, memo)+1;
    if (n%3 == 0) cost = min(cost, dfs(n/3, memo)+1);
    if (n%2 == 0) cost = min(cost, dfs(n/2, memo)+1);

    return memo[n] = cost;
}

int bfs(int n, vector<int> memo) {
    for (int i=2; i <= n; i++) {
        memo[i] = memo[i-1]+1;
        if (i%3 == 0) memo[i] = min(memo[i], memo[i/3]+1);
        if (i%2 == 0) memo[i] = min(memo[i], memo[i/2]+1);
    }

    return memo[n];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> memo1(n+1, -1);
    //cout << dfs(n, memo1);

    vector<int> memo2(n+1, -1);
    memo2[1]=0;
    cout << bfs(n, memo2);
}

/*
dp[i] = min(dp[i-1]+1, dp[i/2]+1, dp[i/3]+1);
*/