//2026.05.02 success
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    struct Node {
        int row;
        int col;
        int count;
    };

    vector<vector<int>> v(101, vector<int>(101, 0));
    for (int i=0; i<rectangle.size(); i++) {
        for (int j=rectangle[i][0]*2; j<=rectangle[i][2]*2; j++) {
            for (int k=rectangle[i][1]*2; k<=rectangle[i][3]*2; k++) {
                v[j][k] = 1;
            }
        }
    }

    for (int i=0; i<rectangle.size(); i++) {
        for (int j=rectangle[i][0]*2+1; j<=rectangle[i][2]*2-1; j++) {
            for (int k=rectangle[i][1]*2+1; k<=rectangle[i][3]*2-1; k++) {
                v[j][k] = 0;
            }
        }
    }

    queue<Node> q;
    q.push({characterX*2, characterY*2, 0});
    v[characterX*2][characterY*2] = 0;

    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    while (!q.empty()) {
        int r = q.front().row;
        int c = q.front().col;
        int cnt = q.front().count;
        q.pop();

        if (r == itemX*2 && c == itemY*2) return cnt/2;
        for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (0 <= nr && nr < v.size() && 0 <= nc && nc < v[0].size()) {
                if (v[nr][nc] == 1) {
                    q.push({nr, nc, cnt+1});
                    v[nr][nc] = 0;
                }
            }
        }
    }
}
