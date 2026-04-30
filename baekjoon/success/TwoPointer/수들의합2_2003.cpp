//2026.04.11 success
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int start = 0, end = 0;
    int sum = 0;
    int cnt = 0;

    while (true) {
        if (sum >= m) {
            sum -= v[start];
            start++;
        } else if (end == n) {
            break;
        } else {
            sum += v[end];
            end++;
        }

        if (sum == m) {
            cnt++;
        }
    }

    cout << cnt;
}
