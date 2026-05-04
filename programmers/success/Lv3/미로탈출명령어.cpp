//2026.05.04 success
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    vector<vector<int>> v(n+1, vector<int>(m+1, 0));
    v[r][c] = 1;

    struct Node {
        string str;
        int row;
        int col;

        bool operator<(const Node& other) const {
            return str > other.str;
        }
    };

    priority_queue<Node> pq;
    pq.push({"", x, y});

    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    string answer = "";
    while (!pq.empty()) {
        string str = pq.top().str;
        int row = pq.top().row;
        int col = pq.top().col;
        pq.pop();
 
        int remain = k - str.length();
        if (row == r && col == c && remain == 0) {
            return str;
        }
        
        int dist = abs(row-r) + abs(col-c) ;
        if (remain < dist) continue;
        if ((remain - dist)%2 != 0) continue;


        for (int i=0; i<4; i++) {
            int r = row + dr[i];
            int c = col + dc[i];
            string s = str;
            if (1 <= r && r <= n && 1 <= c && c <= m) {
                if (i==0) s.push_back('d');
                if (i==1) s.push_back('u');
                if (i==2) s.push_back('r');
                if (i==3) s.push_back('l');
                pq.push({s, r, c});
            }
        }
    }

    if (answer.length() == 0) return "impossible";
    return answer;
}