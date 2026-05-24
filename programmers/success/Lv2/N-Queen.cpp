//2026.05.08 success
#include <vector>
using namespace std;

void markAttack(vector<vector<bool>>& board, int row, int col, int n) {
    for (int r = 0; r < n; r++) board[r][col] = true;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (r - c == row - col || r + c == row + col) {
                board[r][c] = true;
            }
        }
    }
    board[row][col] = true;
}

void dfs(int row, int n, vector<vector<bool>>& board, int& answer) {
    if (row == n) {
        answer++;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (board[row][c]) continue;
        
        vector<vector<bool>> snapshot = board;
        markAttack(board, row, c, n);
        
        dfs(row + 1, n, board, answer);
        
        board = snapshot;
    }
}

int solution(int n) {
    int answer = 0;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    dfs(0, n, board, answer);
    return answer;
}