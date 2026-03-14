#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int ans = INT_MIN;
    int value = 0;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;

        if (value + a >= 0) {
            value += a;
            ans = max(ans, value);
        } else {
            value = 0;
            ans = max(ans, a);
        }
    }

    cout << ans;
}

/*
2 1 = 3 
-4
3 4 = 7
-4
6 5 = 11
-5
1 = 1
*/