//2026.05.16 success
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node {
    string name;
    bool check;
};

bool dfs(vector<vector<string>>& tickets, unordered_map<string, vector<Node>>& m, vector<string>& answer, string begin) {
    if (answer.size() == tickets.size()+1) return true;

    for (auto& x : m[begin]) {
        if (x.check) continue;

        x.check = true;
        answer.push_back(x.name);

        if(dfs(tickets, m, answer, x.name)) return true;

        x.check = false;
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
        sort(x.second.begin(), x.second.end(), [](Node& a, Node& b) {
            return a.name < b.name;
        });
    }

    vector<string> answer;
    answer.push_back("ICN");
    
    dfs(tickets, m, answer, "ICN");

    return answer;
}