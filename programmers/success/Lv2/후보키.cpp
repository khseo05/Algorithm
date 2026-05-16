//2026.05.05 fail
//2026.05.11 fail
//2026.05.16 success
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool isUnique(vector<vector<string>> relation, int mask) {
    unordered_map<string, bool> m;

    for (int i=0; i<relation.size(); i++) {
        string str;
        for (int j=0; j<relation[0].size(); j++) {
            if (!(mask & (1 << j))) continue;
            str += relation[i][j];
        }
        if (m[str]) return false;
        m[str] = true;
    }

    return true;
}

int solution(vector<vector<string>> relation) {
    int size = relation.size();

    vector<int> answer;

    for (int mask = 1; mask < (1 << relation[0].size()); mask++) {
        bool min = true;
        for (int ans : answer) {
            if ((mask & ans) == ans) {
                min = false;
                break;
            }
        }

        if (!min) continue;

        if (isUnique(relation, mask)) {
            answer.push_back(mask);
        }
    }

    return answer.size();
}
