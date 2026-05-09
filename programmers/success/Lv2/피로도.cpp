//2026.05.02 success
//2026.05.09 success
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int answer = -1;
unordered_map<int, bool> m;

void dfs(int& k, vector<vector<int>> dungeons, int cnt, int ans) {
    answer = max(answer, ans);

    for (int i=0; i<dungeons.size(); i++) {
        if (k >= dungeons[i][0]) {
            if (m[i]) continue;
            m[i] = true;
            k -= dungeons[i][1];
            dfs(k, dungeons, cnt+1, ans+1);
            k += dungeons[i][1];
            m[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, dungeons, 0, 0);
    return answer;
}
