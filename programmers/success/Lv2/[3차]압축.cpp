//2026.06.23 success
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> m;
    for (int i = 0; i < 26; i++) {
        m[string(1, 'A' + i)] = i + 1;
    }

    int i = 0;
    while (i < msg.size()) {
        string w(1, msg[i]);
        int moved = 1;

        for (int j = i + 1; j < msg.size(); j++) {
            string next = w + msg[j];
            if (m.count(next)) {
                w = next;
                moved = j - i + 1;
            } else {
                m[next] = m.size() + 1;
                break;
            }
        }

        answer.push_back(m[w]);
        i += moved;
    }

    return answer;
}
