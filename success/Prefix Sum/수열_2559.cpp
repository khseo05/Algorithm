#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int MaxValue = INT_MIN;
    int pre = 0;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;

        v[i] = a;
        pre += a;
        if (i-m >= 0) pre = pre - v[i-m];
        if (i >= m-1) MaxValue = max(MaxValue, pre);
    }

    cout << MaxValue;
}