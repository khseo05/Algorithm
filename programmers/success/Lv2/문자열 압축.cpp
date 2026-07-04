//2026.07.04 success
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = s.length();

    for (int i = 1; i <= s.length() / 2; i++) {
        string str = "";
        string s1 = s.substr(0, i);
        int count = 1;

        for (int j = i; j < s.length(); j += i) {
            string s2 = s.substr(j, i);
            if (s1 == s2) {
                count++;
            } else {
                str += (count == 1) ? s1 : to_string(count) + s1;
                s1 = s2;
                count = 1;
            }
        }
        str += (count == 1) ? s1 : to_string(count) + s1;

        answer = min(answer, (int)str.length());
    }

    return answer;
}
