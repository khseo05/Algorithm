//2026.05.20 fail
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int cnt = 0;
vector<int> answer;
unordered_map<int, bool> m;

void dfs(int n, long long k, int depth, vector<int>& v) {
    if (depth == n) {
        cnt++;
        if (cnt == k) answer = v;
        return;
    }

    for (int i=1; i<=n; i++) {
        if (m[i]) continue;
        m[i] = true;
        depth++;
        v.push_back(i);
        dfs(n, k, depth, v);
        m[i] = false;
        depth--;
        v.pop_back();
    }
}

vector<int> solution(int n, long long k) {
    vector<int> v;
    dfs(n, k, 0, v);
    return answer;
}