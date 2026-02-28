#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        string str;
        cin >> str;

        bool check = true; 
        stack<char> s;
        for (int i=0; i<str.length(); i++) {
            if (str[i] == '(') {
                s.push(str[i]);
            } else if (!s.empty() && str[i] == ')'){
                s.pop();
            } else {
                cout << "NO" << "\n";
                check = false;
                break;
            }
        }

        if (s.empty() && check == true) cout << "YES" << "\n";
        else if (check == true) cout << "NO" << "\n";
    }
}