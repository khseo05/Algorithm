//2026.04.30 success
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    struct pair {
        int node;
        int cnt;
    };

    int answer = 0;
    vector<int> v[20001];
    for (int i=0; i<edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];

        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<pair> q;
    q.push({1, 0});
    int c = 0;
    unordered_map<int, bool> m;
    m[1] = true;

    while (!q.empty()) {
        int node = q.front().node;
        int a = q.front().cnt;
        q.pop();

        if (c == a) answer += 1;
        else if (c < a) {
            answer = 0;
            answer += 1;
            c = a;
        }

        for (int next : v[node]) {
            if (!m[next]) {
                m[next] = true;
                q.push({next , a+1});
            }
        }
    }
    return answer;
}
