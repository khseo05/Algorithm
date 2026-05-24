//2026.05.20 fail
//2026.05.23 fail
//2026.05.24 success
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    for (int i=0; i<name.length(); i++) {
        answer = min(name[i] - 'A', 'Z' - name[i] + 1) + answer;
    }

    int minCount = name.length() - 1;
    for (int i=0; i<name.length(); i++) {
        int idx = i + 1;
        while (idx < name.length() && name[idx] == 'A') {
            idx++;
        }

        int left = i + i + (name.length() - idx);
        int right = (name.length() - idx) + (name.length() - idx) + i;

        minCount = min({minCount, left, right});
    }

    return answer+minCount;
}
