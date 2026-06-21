//2026.06.21 success
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    unordered_map<string, bool> m;
    unordered_map<int,int> m2;

    char lastC = words[0][0];
    int idx = 1;
    for (string w : words) {
        if (idx > n) idx = 1;
        m2[idx]++;
        if (m[w] || lastC != w[0]) {
            answer[0] = idx;
            answer[1] = m2[idx];
            break;
        }
        m[w] = true;
        lastC = w.back();
        idx++;
    }

    return answer;
}
