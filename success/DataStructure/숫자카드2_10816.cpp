#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    unordered_map<int, int> map(n);
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        map[a]++;
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int b;
        cin >> b;
        cout << map[b] << " ";
    }
}