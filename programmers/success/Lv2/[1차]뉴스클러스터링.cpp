//2026.06.22 success
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int solution(string str1, string str2) {
    for (auto& x : str1) x = tolower(x);
    for (auto& x : str2) x = tolower(x);

    unordered_map<string, int> m1;
    unordered_map<string, int> m2;
    set<string> s;

    for (int i = 0; i < (int)str1.size() - 1; i++) {
        string str = str1.substr(i, 2);
        if (str[0] < 'a' || str[0] > 'z') continue;
        if (str[1] < 'a' || str[1] > 'z') continue;
        m1[str]++;
        s.insert(str);
    }

    for (int i = 0; i < (int)str2.size() - 1; i++) {
        string str = str2.substr(i, 2);
        if (str[0] < 'a' || str[0] > 'z') continue;
        if (str[1] < 'a' || str[1] > 'z') continue;
        m2[str]++;
        s.insert(str);
    }

    if (s.empty()) return 65536;

    double intersect = 0, uni = 0;
    for (auto& x : s) {
        int a = m1.count(x) ? m1[x] : 0;
        int b = m2.count(x) ? m2[x] : 0;
        intersect += min(a, b);
        uni += max(a, b);
    }

    return (int)((intersect / uni) * 65536);
}
