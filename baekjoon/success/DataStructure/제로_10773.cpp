#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    stack<int> s;

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;

        if (a != 0) s.push(a);
        else s.pop();
    }

    int size = s.size();
    int ans = 0;
    for (int i=0; i<size; i++) {
        int b = s.top();
        ans += b;
        s.pop();
    }

    cout << ans;
}