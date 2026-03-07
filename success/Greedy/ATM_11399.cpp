//2026-3-1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        v[i] = a;
    }

    sort(v.begin(), v.end());

    int cost=0;
    int ans=0;
    for (int i=0; i<n; i++) {
        cost = v[i] + cost;
        ans += cost;
    }

    cout << ans;
}

/*
1 2 3 3 4
1
1+2=3
3+3=6
6+3=9
9+4=13

1+3+6+9+13=32
*/