//2026.06.27 success
#include <string>
#include <vector>

using namespace std;

void quade(vector<int>& answer, vector<vector<int>>& arr, int br, int bc, int er, int ec) {
    if (br == er && bc == ec) return;

    bool correct = true;
    int val = arr[br][bc];
    for (int i=br; i<er; i++) {
        for (int j=bc; j<ec; j++) {
            if (val != arr[i][j]) {
                correct = false;
                break;
            }
        }
        if (!correct) break;
    }

    if (!correct) {
        int halfR = (br + er) / 2;
        int halfC = (bc + ec) / 2;
        quade(answer, arr, br,    bc,    halfR, halfC);
        quade(answer, arr, br,    halfC, halfR, ec);
        quade(answer, arr, halfR, bc,    er,    halfC);
        quade(answer, arr, halfR, halfC, er,    ec);
    } else {
        if (val == 0) answer[0]++;
        else answer[1]++;
    }

    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);

    int size = arr[0].size();
    quade(answer, arr, 0, 0, size, size);

    return answer;
}
