//2026.05.17 fail
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 1e9;

    for (int mask = 0; mask < (1 << beginning.size()); mask++) {

        int cnt = 0;
        int x = mask;
        while (x) {
            if (x & 1) cnt++;
            x >>= 1;
        }

        bool ok = true;

        for (int c = 0; c < beginning[0].size(); c++) {
            bool needFlip;
            for (int r = 0; r < beginning.size(); r++) {
                int cur = beginning[r][c];

                if (mask & (1 << r)) {
                    cur ^= 1;
                }

                bool diff = (cur != target[r][c]);

                if (r == 0) {
                    needFlip = diff;
                } else if (needFlip != diff) {
                    ok = false;
                    break;
                }
            }

            if (!ok) break;
            if (needFlip) {
                cnt++;
            }
        }

        if (ok) {
            answer = min(answer, cnt);
        }
    }

    return answer == 1e9 ? -1 : answer;
}