//2026_04_06 success
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
    
    int start = 0, end  = v.size()-1;
    sort(v.begin(), v.end());
    int x=0, cnt=0;
    cin >> x;
    
    while (start != end) {
        if (v[start] + v[end] == x) {
            cnt++;
            start += 1;
        } else if (v[start] + v[end] > x) {
            end -= 1;
        } else {
            start += 1;
        }
    }
    
    cout << cnt;
}