//2026.06.04 fail
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> v;
    for (int i=0; i<24; i++) {
        vector<int> w;
        for (int j : v) {
            if (j > i) w.push_back(j);
        }
        v = w;

        int need = players[i] / m;
        int add = need - v.size();
        if (add > 0) {
            answer += add;
            for (int j=0; j<add; j++) {
                v.push_back(i + k);
            }
        }
    }

    return answer;
}
