#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> memo(11);
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;

    for (int i=4; i<11; i++) {
        memo[i] = memo[i-1]+memo[i-2]+memo[i-3];
    }

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            cout << 1 << "\n";
        } else if (a == 2) {
            cout << 2 << "\n";
        } else if (a == 3) {
            cout << 4 << "\n";
        } else {
            cout << memo[a] << "\n";
        }
    }
}


