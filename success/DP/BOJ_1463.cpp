#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dp(int n, vector<int>& memo) {
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n];

    int cost = dp(n-1, memo)+1;
    if (n % 3 == 0) cost = min(cost, dp(n/3, memo)+1);
    if (n % 2 == 0) cost = min(cost, dp(n/2, memo)+1);

    return memo[n] = cost;
}

int main() {
    int n;
    cin >> n;

    vector<int> memo(n+1, -1);
    cout << dp(n, memo);
}