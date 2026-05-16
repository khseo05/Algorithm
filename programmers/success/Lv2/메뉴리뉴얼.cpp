//2026.05.04 fail
//2026.05.16 success
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int c : course) {
        unordered_map<string, int> m;
        int maxcnt = 0;

        for (string o : orders) {
            for (int mask=1; mask < (1 << o.length()); mask++) {
                string s;

                for (int j=0; j<o.length(); j++) {
                    if (mask & (1 << j)) {
                        s += o[j];
                    }
                }

                if (s.length() == c) {
                    sort(s.begin(), s.end());

                    m[s]++;
                    maxcnt = max(maxcnt, m[s]);
                }
            }
        }

        for (auto x : m) {
            if (x.second >= 2 && x.second == maxcnt) {
                answer.push_back(x.first);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}
