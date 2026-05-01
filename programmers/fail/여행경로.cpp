//2026.05.01 fail
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node {
        string str;
        bool check = false;
};

bool dfs(string begin, unordered_map<string, vector<Node>>& m, vector<string>& answer, int ticketCount) {
    if (answer.size() == ticketCount + 1) return true;

    for (Node& next : m[begin]) {
        if (next.check) continue;

        next.check = true;
        answer.push_back(next.str);

        if(dfs(next.str, m, answer, ticketCount)) return true;

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
            return a.str < b.str;
        });
    }

    vector<string> answer;
    answer.push_back("ICN");

    dfs("ICN", m, answer, tickets.size());

    return answer;
}
