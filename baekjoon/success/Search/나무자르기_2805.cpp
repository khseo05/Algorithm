//2026.03.10 fail
//2026.03.15 success
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long tree(vector<int> v, long long m, int left, int right) {
    long long mid;

    while (left <= right) { 
        mid = (left+right)/2;
        long long height = 0;
        for (int i=0; i<v.size(); i++) {
            if (v[i] > mid) height += v[i]-mid;
        }

        if (height < m) {
            right = mid-1;
        } else if (height >= m) {
            left = mid+1;
        }
    }

    return right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    cin >> n >> m;

    vector<int> v(n, 0);
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        v[i] = a;
    }

    sort(v.begin(), v.end());

    cout << tree(v, m, 0, v[v.size()-1]);
}