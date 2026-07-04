//2026.07.04 success
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int row;
    int col;
    int dist;
};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    for (auto& place : places) {
        int n = place.size();
        int m = place[0].size();
        bool safe = true;

        for (int si = 0; si < n && safe; si++) {
            for (int sj = 0; sj < m && safe; sj++) {
                if (place[si][sj] != 'P') continue;

                vector<vector<bool>> visited(n, vector<bool>(m, false));
                queue<Node> q;
                visited[si][sj] = true;
                q.push({si, sj, 0});

                while (!q.empty()) {
                    Node cur = q.front();
                    q.pop();
                    int row = cur.row;
                    int col = cur.col;
                    int dist = cur.dist;

                    if (dist > 0 && place[row][col] == 'P') {
                        safe = false;
                        break;
                    }

                    if (dist >= 2) continue;

                    for (int d = 0; d < 4; d++) {
                        int nr = row + dr[d];
                        int nc = col + dc[d];
                        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                        if (visited[nr][nc]) continue;
                        if (place[nr][nc] == 'X') continue;

                        visited[nr][nc] = true;
                        q.push({nr, nc, dist + 1});
                    }
                }
            }
        }

        answer.push_back(safe ? 1 : 0);
    }

    return answer;
}
