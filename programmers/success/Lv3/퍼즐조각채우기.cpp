//2026.06.04 fail
//2026.06.06 success
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void piece(vector<vector<pair<int, int>>>& v, vector<vector<int>>& board) {
    queue<pair<int, int>> q;
    int idx = 0;

    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].size(); j++) {
            if (board[i][j] == 0) continue;
            q.push({i, j});
            board[i][j] = 0;
            vector<pair<int,int>> cur;

            while (!q.empty()) {
                int row = q.front().first;
                int col = q.front().second;

                cur.push_back({row, col});

                q.pop();

                for (int k=0; k<4; k++) {
                    int r = row + dr[k];
                    int c = col + dc[k];
                    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) continue;
                    if (board[r][c] == 1) {
                        board[r][c] = 0;
                        q.push({r, c});
                    }
                }
            }
            v.push_back(cur);
        }
    }
}

vector<pair<int, int>> normalize(vector<pair<int, int>> p) {
    sort(p.begin(), p.end());

    int br = p[0].first, bc = p[0].second;
    for (auto& [r, c] : p) {r -= br; c -= bc;}

    return p;
}

vector<pair<int,int>> rotate90(vector<pair<int,int>> v) {
    for (auto& [r, c] : v) {
        int tmp = r;
        r = c;
        c = -tmp;
    }
    return normalize(v);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    for (int i=0; i<game_board.size(); i++) {
        for (int j=0; j<game_board[0].size(); j++) {
            if (game_board[i][j] == 0) game_board[i][j] = 1;
            else game_board[i][j] = 0;
        }
    }

    vector<vector<pair<int, int>>> ng;
    vector<vector<pair<int, int>>> nt;

    piece(ng, game_board);
    piece(nt, table);

    vector<bool> used(nt.size(), false);
    for (auto& x : ng) {
        auto nb = normalize(x);
        for (int i=0; i<nt.size(); i++) {
            if (used[i]) continue;
            auto p = normalize(nt[i]);
            bool matched = false;
            for (int rot=0; rot<4; rot++) {
                if (nb == p) {
                    used[i] = true;
                    matched = true;
                    answer += x.size();
                    break;
                }
                p = rotate90(p);
            }
            if (matched) break;
        }
    }

    return answer;
}
