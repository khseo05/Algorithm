//2026.06.27 success
#include <string>
#include <vector>

using namespace std;

void twotwo(vector<string>& board, int& answer) {
    vector<vector<bool>> v(board.size(), (vector<bool>(board[0].size(), false)));
    for (int i=0; i<board.size()-1; i++) {
        for (int j=0; j<board[0].size()-1; j++) {
            if ((board[i][j] == board[i][j+1]) && (board[i][j] == board[i+1][j]) && (board[i][j] == board[i+1][j+1])) {
                v[i][j] = true;
                v[i][j+1] = true;
                v[i+1][j] = true;
                v[i+1][j+1] = true;
            }
        }
    }

    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].size(); j++) {
            if (v[i][j] && board[i][j] != '0') {
                board[i][j] = '0';
                answer++;
            }
        }
    }
}

void down(vector<string>& board, int m, int n) {
    while (true) {
        bool moved = false;
        for (int i = 0; i < m-1; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '0' && board[i+1][j] == '0') {
                    board[i+1][j] = board[i][j];
                    board[i][j] = '0';
                    moved = true;
                }
            }
        }
        if (!moved) return;
    }
}

int solution(int m, int n, vector<string> board) {

    int answer = 0;
    while (true) {
        int before = answer;
        twotwo(board, answer);
        down(board, m, n);
        if (before == answer) break;
    }
    return answer;
}
