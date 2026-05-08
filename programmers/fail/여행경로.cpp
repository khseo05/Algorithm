//2026.05.01 fail
//2026.05.05 fail
//2026.05.08 fail
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node {
    string name;
    bool check;
};

bool dfs (unordered_map<string, vector<Node>>& m, vector<string>& answer, string begin, int cnt) {
    if (answer.size() == cnt+1) return true;

    for (Node& next : m[begin]) {
        if (next.check) continue;

        next.check = true;
        answer.push_back(next.name);
        if (dfs(m, answer, next.name, cnt)) return true;;
        next.check = false;
        answer.pop_back();
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    unordered_map<string, vector<Node>> m;
    for (int i=0; i<tickets.size(); i++) {
        string a = tickets[i][0];
        string b = tickets[i][1];
        m[a].push_back({b, false});
    }

    for (auto& x : m) {
        sort(x.second.begin(), x.second.end(), [](Node a, Node b) {
            return a.name < b.name;
        });
    }

    vector<string> answer;
    answer.push_back("ICN");

    dfs(m, answer, "ICN", tickets.size());
    return answer;
}
