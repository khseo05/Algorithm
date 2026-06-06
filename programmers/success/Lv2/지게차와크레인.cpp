//2026.05.30 success
//2026.06.06 success
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool zero(const vector<vector<char>>& v, int i, int j) {
    int R = v.size(), C = v[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    struct Node { int r, c; };
    queue<Node> q;
    q.push({i, j});
    visited[i][j] = true;

    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        if (r==0 || r==R-1 || c==0 || c==C-1) return true;

        for (int d = 0; d < 4; d++) {
            int row = r + dr[d];
            int col = c + dc[d];
            if (row >= 0 && row < R && col >= 0 && col < C
                && !visited[row][col] && v[row][col] == '0') {
                visited[row][col] = true;
                q.push({row, col});
            }
        }
    }
    return false;
}

int solution(vector<string> storage, vector<string> requests) {
    vector<vector<char>> v(storage.size(), vector<char>(storage[0].size(),'0'));

    for (int i=0; i<storage.size(); i++) {
        string str = storage[i];
        for (int j=0; j<storage[0].size(); j++) {
            v[i][j] = str[j];
        }
    }

    for (int i=0; i<requests.size(); i++) {
        string s = requests[i];
        if (s.length()==2) {
            for (int i=0; i<v.size(); i++) {
                for (int j=0; j<v[0].size(); j++) {
                    if (v[i][j] == s[0]) v[i][j] = '0';
                }
            }
        } else {
            vector<vector<char>> fake = v;
            for (int i=0; i<v.size(); i++) {
                for (int j=0; j<v[0].size(); j++) {
                    if (fake[i][j] == s[0] && zero(fake, i, j)) {
                        v[i][j] = '0';
                    }
                }
            }
        }
    }

    int answer = 0;
    for (int i=0; i<v.size(); i++)  {
        for (int j=0; j<v[0].size(); j++) {
            if (v[i][j] == '0') continue;
            answer++;
        }
    }

    return answer;
}
