#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    unordered_map<int, int> mp;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        mp[a] +=1;
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int b;
        cin >> b;
        if (mp.find(b) != mp.end()) {
            cout << mp[b] << " ";
        } else { 
            cout << 0 << " ";
        }
    }
}