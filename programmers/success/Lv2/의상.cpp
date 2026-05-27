//2026.05.27 success
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, vector<string>> m;

    int answer = 1;
    for (int i=0; i<clothes.size(); i++) {
        m[clothes[i][1]].push_back(clothes[i][0]);
    }

    for (auto x : m) {
        answer *= (x.second.size() + 1);
    }

    return answer-1;
}
