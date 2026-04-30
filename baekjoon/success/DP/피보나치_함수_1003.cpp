#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fibo(vector<pair<int, int>>& memo) {
    for (int i=2; i<41; i++) {
        memo[i].first = memo[i-1].first + memo[i-2].first;
        memo[i].second = memo[i-1].second + memo[i-2].second;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> memo(41);
    memo[0].first = 1;
    memo[0].second = 0;
    memo[1].first = 0;
    memo[1].second = 1;

    fibo(memo);

    for (int i=0; i<n; i++) {
        int m;
        cin >> m;
        cout << memo[m].first << " " << memo[m].second << "\n";
    }
}

/*
0   1 0
1   0 1
2   1 1 fibo(1) + fibo(0)
3   1 2 fibo(2) + fibo(1)
4   2 3 fibo(3) + fibo(2)
5   3 5
6   5 8
*/