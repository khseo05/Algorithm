#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    queue<int> q;

    for (int i=1; i<=n; i++) {
        q.push(i);
    }

    while (true) {
        if (q.size() == 1) break;
        q.pop();
        int a = q.front();
        q.pop();
        q.push(a);
    }

    cout << q.front();
}