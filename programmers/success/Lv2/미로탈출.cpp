//2026.05.24 success
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Pair {
    int answer = 0;
    int row = 0;
    int col = 0;
};

void bfs(Pair& p, vector<string> maps, char target) {
    queue<Pair> q;
    q.push({0, p.row, p.col});
    maps[p.row][p.col] = 'X';

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        Pair pp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int n = pp.row + dr[i];
            int m = pp.col + dc[i];
            if (n < 0 || n >= (int)maps.size()) continue;
            if (m < 0 || m >= (int)maps[0].size()) continue;
            if (maps[n][m] == 'X') continue;

            if (maps[n][m] == target) {
                p.row = n;
                p.col = m;
                p.answer += pp.answer + 1;
                return;
            }

            q.push({pp.answer + 1, n, m});
            maps[n][m] = 'X';
        }
    }
    p.answer = -1;
}

int solution(vector<string> maps) {
    Pair p;
    for (int i = 0; i < (int)maps.size(); i++) {
        for (int j = 0; j < (int)maps[0].size(); j++) {
            if (maps[i][j] == 'S') {
                p.row = i;
                p.col = j;
            }
        }
    }

    bfs(p, maps, 'L');
    if (p.answer == -1) return -1;
    bfs(p, maps, 'E');
    return p.answer;
}
