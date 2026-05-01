//2026.04.30 fail
//2026.05.01 ref
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int solution(vector<vector<int>> board) {
    struct Node {
        int cost, row, col, dir;

        bool operator<(const Node& other) const{
            return cost > other.cost;
        }
    };

    priority_queue<Node> pq;
    vector<vector<vector<int>>> dist(
        board.size(), 
        vector<vector<int>>(board[0].size(), vector<int>(2, INT_MAX))
    );
    pq.push({0, 0, 0, -1});
    
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};
    int answer = INT_MAX;

    while (!pq.empty()) {
        int cost = pq.top().cost;
        int row = pq.top().row;
        int col = pq.top().col;
        int dir = pq.top().dir;
        pq.pop();

        for (int i=0; i<4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (0 <= nr && nr < board.size() && 0 <= nc && nc < board[0].size()) {
                if (board[nr][nc] == 0) {
                    int ncost;
                    // 동/서:1 남/북:2 남:3 북:4
                    if (dir == -1) {
                        ncost = 100;
                        if (nr == board.size()-1 && nc == board[0].size()-1) {
                                answer = min(ncost, answer);
                        }
                        if(i == 0 || i == 1) {
                            if(ncost < dist[nr][nc][1]) {
                                dist[nr][nc][1] = ncost;
                                pq.push({ncost, nr, nc, 2});
                            }
                        } else {
                            if(ncost < dist[nr][nc][0]) {
                                dist[nr][nc][0] = ncost;
                                pq.push({ncost, nr, nc, 1});
                            }
                        }
                        continue;
                    }
                    if (dir == 1) {
                        if (i == 2 || i == 3) {
                            ncost = cost + 100;
                            if (nr == board.size()-1 && nc == board[0].size()-1) {
                                answer = min(ncost, answer);
                            }
                            if (ncost >= dist[nr][nc][0]) continue;
                            dist[nr][nc][0] = ncost;
                            pq.push({ncost, nr, nc, 1});
                        } else if (i == 0 || i == 1) {
                            ncost = cost + 600;
                            if (nr == board.size()-1 && nc == board[0].size()-1) {
                                answer = min(ncost, answer);
                            }
                            if (ncost >= dist[nr][nc][1]) continue;
                            dist[nr][nc][1] = ncost;
                            pq.push({ncost, nr, nc, 2});
                        }
                    }

                    if (dir == 2) {
                        if (i == 0 || i == 1) {
                            ncost = cost + 100;;
                            if (nr == board.size()-1 && nc == board[0].size()-1) {
                                answer = min(ncost, answer);
                            }
                            if (ncost >= dist[nr][nc][1]) continue;
                            dist[nr][nc][1] = ncost;
                            pq.push({ncost, nr, nc, 2});
                        } else if (i == 2 || i == 3) {
                            ncost = cost + 600;
                            if (nr == board.size()-1 && nc == board[0].size()-1) {
                                answer = min(ncost, answer);
                            }
                            if (ncost >= dist[nr][nc][0]) continue;
                            dist[nr][nc][0] = ncost;
                            pq.push({ncost, nr, nc, 1});
                        }
                    }
                }    
            }
        }
    }

    return answer;
}