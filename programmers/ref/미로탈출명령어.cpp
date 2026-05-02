//2026.05.02 ref
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    vector<vector<int>> v(n, vector<int>(m, 0));
    v[r][c] = 1;

    struct Node {
        string answer;
        int row;
        int col;
    };

    queue<Node> q;
    q.push({"", x-1, y-1});

    string ans;
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    while (!q.empty()) {
        int r = q.front().row;
        int c = q.front().col;
        string a = q.front().answer;
        q.pop();

        if (ans.length() == 0) ans = a;
        else if (a.length() == k && a < ans) ans = a;
        else if (a.length() > k) continue;

        for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (0 <= nr && nr < n && 0 <= nc && nc < m) {
                if (i==0) q.push({a+"u", nr, nc});
                if (i==1) q.push({a+"d", nr, nc});
                if (i==2) q.push({a+"r", nr, nc});
                if (i==3) q.push({a+"l", nr, nc});
            }
        }
    }

    if (ans.length() == 0) return "impossible";
    else return ans;
}
