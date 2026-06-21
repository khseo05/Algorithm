//2026.06.21 success
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;
    for (string city : cities) {
        for (auto& c : city) c = tolower(c);
        auto x = find(v.begin(), v.end(), city);
        if (x != v.end()) {
            v.erase(x);
            v.push_back(city);
            answer += 1;
        } else {
            if (cacheSize == 0) {
                answer += 5;
                continue;
            }
            if (v.size() == cacheSize) v.erase(v.begin());
            v.push_back(city);
            answer += 5;
        }
    }
    return answer;
}
