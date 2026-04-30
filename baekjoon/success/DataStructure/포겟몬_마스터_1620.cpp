#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    unordered_map<string, int> map;
    unordered_map<int, string> rmap;
    for (int i=0; i<n; i++) {
        string str;
        cin >> str;

        map[str] = i+1;
        rmap[i] = str;
    }

    for (int i=0; i<m; i++) {
        string str;
        cin >> str;
        if (map[str]) cout << map[str] << "\n";
        else {
            int n = stoi(str)-1;
            cout << rmap[n] << "\n";
        }
    }
}