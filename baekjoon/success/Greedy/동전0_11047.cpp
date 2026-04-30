#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a > k) continue;
        v.push_back(a);
    }

    int cnt = 0;
    for (int i=v.size()-1; i >= 0; i--) {
        if (k == 0) break;
        while (true) {
            if (k >= v[i]) {
                cnt++;
                k = k - v[i];
            } else {
                break;
            }
        }
    }

    cout << cnt;
}