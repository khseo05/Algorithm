//2026.05.27 success
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day;

    for (int  i=0; i<progresses.size(); i++) {
        day.push_back(ceil((100.0 - progresses[i])/speeds[i]));
    }

    int i = 0;
    while (i < progresses.size()) {
        int cnt = 0;
        while (i + cnt < progresses.size() && day[i+cnt] <= day[i]) {
            cnt++;
        }

        answer.push_back(cnt);
        i += cnt;
    }

    return answer;
}
