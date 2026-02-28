#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n  >> m;
    unordered_map<string,bool> map;

    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        map[str] = true;
    }

    vector<string> ans;
    int cnt =0;

    for (int i=0; i<m; i++) {
        string str;
        cin >> str;
        if (map.find(str) != map.end()) {
            ans.push_back(str);
            cnt++;
        }
    } 

    sort(ans.begin(), ans.end());

    cout << cnt << "\n";
    for (string str : ans) {
        cout << str << "\n";
    }
}