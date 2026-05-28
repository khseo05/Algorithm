//2026.05.28 success
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> solution(vector<string> operations) {
    deque<int> d;

    for (int i=0; i<operations.size(); i++) {
        string str = operations[i];
        if (str[0] == 'I') {
            string s;

            if (str[2] == '-') {
                for (int j=3; j<str.length(); j++) {
                    s.push_back(str[j]);
                }
                d.push_back(-stoi(s));
            } else {
                for (int j=2; j<str.length(); j++) {
                    s.push_back(str[j]);
                }
                d.push_back(stoi(s));
            }

            sort(d.begin(), d.end());
        }

        if (!d.empty() && str == "D 1") d.pop_back();
        if (!d.empty() && str == "D -1") d.pop_front();
    }

    if (d.empty()) return {0, 0};

    return {d.back(), d.front()};
}
