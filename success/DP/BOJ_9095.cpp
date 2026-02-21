#include <iostream>
#include <vector>
using namespace std;

int dp(int n, vector<int>& memo) {
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];

    int cost = 0;
    cost += dp(n-1, memo);
    if (n>1) cost += dp(n-2, memo);
    if (n>2) cost += dp(n-3, memo); 
    
    return memo[n] = cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> memo(11, -1);

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        cout << dp(a, memo) << "\n";
    }
}