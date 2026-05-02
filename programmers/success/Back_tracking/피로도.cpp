//2026.05.02 success
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int k, vector<vector<int>>& dungeons, vector<bool>& visited, int count) {
    for (int i=0; i<dungeons.size(); i++) {
        if (visited[i]) continue;

        if (k >= dungeons[i][0]) {
            visited[i] = true;
            count = max(dfs(k - dungeons[i][1], dungeons, visited, count+1), count);
            visited[i] = false;
        }
    }

    return count;
}

int solution(int k, vector<vector<int>> dungeons) {

    int answer = 0;
    vector<bool> visited(dungeons.size(), false);
    answer = dfs(k, dungeons, visited, 0);

    return answer;
}
