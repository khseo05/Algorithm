//2026.05.27 success
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node {
    int p;
    int n;

    bool operator <(const Node& other) const {
        if (p == other.p) return n < other.n;
        return p > other.p;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<Node>> m;
    unordered_map<string, int> total;

    for (int i=0; i<genres.size(); i++) {
        m[genres[i]].push_back({plays[i], i});
        total[genres[i]] += plays[i];
    }

    vector<pair<string, int>> v(total.begin(), total.end());
    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    for (auto x : v) {
        auto& node = m[x.first];
        sort(node.begin(), node.end());
        for (int i=0; i<min((int)node.size(),  2); i++)  {
            answer.push_back(node[i].n);
        }
    }

    return answer;
}
