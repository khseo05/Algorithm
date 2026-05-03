//2026.05.03 success
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = (brown-4)/2;
    int row;
    int col;

    if (total % 2 == 0) {
        row = total/2;
        col = total/2;
    } else {
        row = total/2+1;
        col = total/2;
    }

    while (true) {
        if (row * col == yellow) break;
        row += 1;
        col -= 1;
    }

    vector<int> answer;
    answer.push_back(row+2);
    answer.push_back(col+2);
    return answer;
}

/*
b b b b
b y y b
b b b b

*/
