//2026.05.03 success
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> v(n, vector<int>(n, 0));
    int num = 1;
    int top = 0;
    int bottom = n-1;

    while (top <= bottom) {
        for (int i = top; i <= bottom; i++) {
            if (v[i][top] != 0) continue;
            v[i][top] = num;
            num += 1;
        }

        for (int j = top+1; j <= bottom; j++) {
            if (v[bottom][j] != 0) continue;
            v[bottom][j] = num;
            num += 1;
        }

        for (int i = bottom-1; i >= top+1; i--) {
            if (v[i][i-top] != 0) continue;
            v[i][i-top] = num;
            num += 1;
        }

        top++;
        bottom--;
    }

    vector<int> answer;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            answer.push_back(v[i][j]);

    return answer;
}
