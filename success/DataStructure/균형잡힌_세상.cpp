#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    while (true) {
        getline(cin, str);
        if (str == ".") break;
        stack<char> s;
        bool check = true;
        for (char c : str) {
            if (c == '(' || c == '[') s.push(c);
            else if (c == ')') {
                if (!s.empty() && s.top() == '(') s.pop();
                else {
                    check = false;
                    break;
                }
            }
            else if (c == ']') {
                if (!s.empty() && s.top() == '[') s.pop();
                else {
                    check = false;
                    break;
                }
            }
        }

        if (s.empty() && check) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}