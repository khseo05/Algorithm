//2026.06.24 success
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, int> inTime;
    map<string, int> totalTime;

    for (string re : records) {
        stringstream ss(re);
        string token;
        int time = 0;
        string carNum = "";

        while (getline(ss, token, ' ')) {
            if (token.find(':') != string::npos) {
                string t = "";
                for (auto x : token) {
                    if (x == ':') {
                        time += stoi(t) * 60;
                        t = "";
                    } else t += x;
                }
                time += stoi(t);
            } else if (token[0] != 'I' && token[0] != 'O') {
                carNum = token;
            }
        }

        if (!inTime.count(carNum)) {
            inTime[carNum] = time;
        } else {
            totalTime[carNum] += time - inTime[carNum];
            inTime.erase(carNum);
        }
    }

    int closing = 23 * 60 + 59;
    for (auto& [carNum, t] : inTime) {
        totalTime[carNum] += closing - t;
    }

    for (auto& [carNum, total] : totalTime) {
        int fee = fees[1];
        if (total > fees[0]) {
            fee += ((total - fees[0]) + fees[2] - 1) / fees[2] * fees[3];
        }
        answer.push_back(fee);
    }

    return answer;
}
