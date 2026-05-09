//2026.05.03 success
//2026.05.09 success
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int b = (brown - 4) / 2;
    int row = b;
    int col = 0;

    vector<int> answer;
    while (row >= col) {
        if (row * col == yellow) {
            answer.push_back(row+2);
            answer.push_back(col+2);
            break;
        }

        row--;
        col++;
    }

    return answer;
}
