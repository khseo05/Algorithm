//2026.03.15 success
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    vector<int> n;
    vector<char> s;

    string cur = "";
    for (char c : str) {
        if (isdigit(c)) {
            cur += c;
        } else {
            n.push_back(stoi(cur));
            cur = "";
            s.push_back(c);
        }
    }
    n.push_back(stoi(cur));

    int ans = n[0];
    int minus = 0;
    bool check = false;
    for (int i=1; i<=s.size(); i++) {
        if (s[i-1] == '-' && !check) check = true;
        else if (s[i-1] == '-' && check) {
            ans -= minus;
            minus = 0;
        }

        if (s[i-1] == '+' && !check) {
            ans += n[i];
        } else if (check) {
            minus += n[i];
        }
    }

    cout << ans - minus;
}