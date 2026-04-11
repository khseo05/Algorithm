// 2026.04.10 success
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    int visited[100001] = {0, };
    
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = 1;

    while (!q.empty()) {
        int location = q.front().first;
        int time = q.front().second;
        q.pop();

        if (location == k) {
            cout << time;
            break;
        }

        if (location > 0 && visited[location - 1] == 0) {
            visited[location - 1] = 1;
            q.push({location - 1, time + 1});
        }

        if (location < 100000 && visited[location + 1] == 0) {
            visited[location + 1] = 1;
            q.push({location + 1, time + 1});
        }

        if (location * 2 <= 100000 && visited[location * 2] == 0) {
            visited[location * 2] = 1;
            q.push({location * 2, time + 1});
        }
    }
}