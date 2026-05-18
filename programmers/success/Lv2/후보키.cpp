//2026.05.05 fail
//2026.05.11 fail
//2026.05.16 success
//2026.05.18 success
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> relation) {
    vector<int> answer;

    for (int mask = 1; mask < (1 << relation[0].size()); mask++) {
        unordered_map<string, bool> m;
        bool isSubset = false;
        for (int ans : answer) {
            if ((mask & ans) == ans) {
                isSubset = true;
                break;
            }
        }

        if (isSubset) continue;

        bool check = true;
        for (int i = 0; i < relation.size(); i++) {
            string s;
            for (int j = 0; j <relation[0].size(); j++) {
                if (mask & (1 << j)) {
                    s += relation[i][j];
                }
            }

            if (m[s]) {
                check = false;
                break;
            }
            m[s] = true;
        }

        if (check) answer.push_back(mask);
    }

    return answer.size();
}
