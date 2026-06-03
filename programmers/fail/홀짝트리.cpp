//2026.06.03 fail
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Pair {
    vector<int> adj;
    int cnt;
};

unordered_map<int, bool> m;
vector<Pair> root(400001);

bool graph(int n, int before, vector<int> answer) {
    for (auto x : root[n].adj) {
        if (m[x]) continue;
        m[x] = true;

        int after = 2;
        if ((x%2==0 && root[x].cnt%2==0) || (x%2!=0 && root[x].cnt%2!=0)) after = 0;
        else after = 1;

        if (before != after) return false;
        if (!graph(x, after, answer)) return false;

        m[x] = false;
    }

    return true;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer;
    root.clear();
    m.clear();
    for (int i=0; i<edges.size(); i++) {
        root[edges[i][0]].adj.push_back(edges[i][1]);
        root[edges[i][1]].adj.push_back(edges[i][0]);
    }

    for (int i=0; i<nodes.size(); i++) {
        root[nodes[i]].cnt = root[nodes[i]].adj.size() - 1;
    }

    for (int n : nodes) {
        int before = 0;

        if ((n%2==0 && (root[n].cnt+1)%2==0) || (n%2!=0 && (root[n].cnt+1)%2!=0)) before = 0;
        else before = 1;

        if(graph(n, before, answer));
    }

    return answer;
}
