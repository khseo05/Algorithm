//2026.05.17 fail
//2026.05.24 success
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 1e9;
    for (int mask = 0; mask < (1 << beginning.size()); mask++) {
        int cnt = 0;
        for (int row = 0; row < beginning.size(); row++) {
            if (mask & (1 << row)) cnt++;
        }

        bool possible = true;

        for (int c = 0; c < beginning[0].size(); c++) {
            bool flag = true;
            for (int r = 0; r < beginning.size(); r++) {
                bool check = false;
                if (mask & (1 << r)) check = true;

                int result = beginning[r][c];
                if ((result != target[r][c] && !check) || (check && 1 - result != target[r][c])) {
                    flag = false;
                    break;
                }
            }

            if (!flag) {
                flag = true;

                for (int r = 0; r < beginning.size(); r++) {
                    bool check = false;
                    if (mask & (1 << r)) check = true;

                    int result = 1 - beginning[r][c];
                    if ((result != target[r][c] && !check) || (check && 1 - result != target[r][c])) {
                        flag = false;
                        break;
                    }
                }

                if (flag) cnt++;
            }

            if (!flag) {
                possible = false;
                break;
            }
        }

        if (possible) {
            answer = min(cnt, answer);
        }
    }

    return answer == 1e9 ? -1 : answer;
}
