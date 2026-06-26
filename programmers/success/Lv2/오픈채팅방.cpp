//2026.06.26 success
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Node {
    string name;
    vector<string> ac;
};

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> v;
    unordered_map<string, Node> m;

    for (string r : record) {
        stringstream ss(r);
        string active, uuid, name;
        ss >> active >> uuid >> name;
        if (active != "Change") v.push_back(uuid);
        if (active == "Enter") {
            m[uuid].name = name;
            m[uuid].ac.push_back(active);
        } else if (active == "Change"){
            m[uuid].name = name;
        } else {
            m[uuid].ac.push_back(active);
        }
    }

    for (string id : v) {
        if (m[id].ac.empty()) continue;

        if (m[id].ac.front() == "Enter") {
            answer.push_back(m[id].name + "님이 들어왔습니다.");
        } else if (m[id].ac.front() == "Leave") {
            answer.push_back(m[id].name + "님이 나갔습니다.");
        }
        m[id].ac.erase(m[id].ac.begin());
    }

    return answer;
}
