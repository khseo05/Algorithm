#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_map<int,int> map;

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        map[a] = 1;
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int b;
        cin >> b;
        if (map[b] == 1) cout << "1" << "\n";
        else cout << "0" << "\n";
    }
}