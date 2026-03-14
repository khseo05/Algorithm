#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Binary(vector<int> v, int left, int right, int m) {
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        int cnt = 0;
        for (int i=0; i<v.size(); i++) {
            cnt += v[i]/mid;
        }

        if (cnt < m) {
            right = mid-1;
        } else if (cnt >= m) {
            left = mid+1;
        }
    }

    return right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);

    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        v[i] = a;
    }

    sort(v.begin(), v.end());

    cout << Binary(v, 1, v[n-1], m);
} 