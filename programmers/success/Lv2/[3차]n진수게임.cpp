//2026.06.23 success
#include <string>
#include <vector>
#include <map>

using namespace std;

string convert(int i, int n, map<int, string> mm) {
    if (i == 0) return "0";
    string s = "";
    while (i > 0) {
        int res = i % n;
        i /= n;

        if (res >= 10) s = mm[res] + s;
        else s = to_string(res) + s;
    }

    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int number = t * m;
    map<int, string> mm;
    mm[10] = "A";
    mm[11] = "B";
    mm[12] = "C";
    mm[13] = "D";
    mm[14] = "E";
    mm[15] = "F";

    string s = "";
    for (int i=0; s.size() < number; i++) {
        s += convert(i, n, mm);
    }

    for (int i = p-1; i <s.size(); i += m) {
        answer += s[i];
    }
    answer = answer.substr(0, t);

    return answer;
}
