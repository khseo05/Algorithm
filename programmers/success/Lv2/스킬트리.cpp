//2026.06.24 success
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, bool> regist;
    for (auto x : skill) {
        regist[x] = true;
    }

    for (string st : skill_trees) {
        unordered_map<char, bool> m;
        bool bb = true;
        for (auto c : st) {
            bool b = true;
            if (!regist[c]) continue;
            for (auto x : skill) {
                if (x == c) {
                    m[x] = true;
                    break;
                }
                if (!m[x]) {
                    b = false;
                    break;
                }
            }
            if(!b) {
                bb = false;
                break;
            }
        }
        if (bb) answer++;
    }
    return answer;
}
