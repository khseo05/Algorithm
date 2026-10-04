//2026.10.04 성공
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct st { 
    int cnt;
    int row;
    int col; 
};

int solution(vector<string> board) {
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    queue<st> q;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'R') {
                q.push({0, i, j});
                visited[i][j] = true;
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [cnt, r, c] = q.front();
        q.pop();

        if (board[r][c] == 'G') return cnt;

        for (int d = 0; d < 4; d++) {
            int nr = r, nc = c;

            while (nr + dr[d] >= 0 && nr + dr[d] < board.size() 
                   && nc + dc[d] >= 0 && nc + dc[d] < board[0].size() 
                   && board[nr + dr[d]][nc + dc[d]] != 'D') {
                nr += dr[d];
                nc += dc[d];
            }
            if (!visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({cnt + 1, nr, nc});
            }
        }
    }
    
    return -1;
}