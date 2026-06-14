//2026.06.14 fail
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

bool check(vector<int> v[], int i, set<int>& s, int start, int parent) {
    for (auto x : v[i]) {
        if (x == parent) continue;
        if (x == start) return true;
        if (s.count(x)) continue;
        s.insert(x);
        if (check(v, x, s, start, i)) return true;
    }
    return false;
}

bool two(vector<int> v[], int i, set<int>& visited, int parent) {
    visited.insert(i);
    if (v[i].size() > 2) return true;
    for (auto x : v[i]) {
        if (x == parent) continue;
        if (visited.count(x)) continue;
        if (two(v, x, visited, i)) return true;
    }
    return false;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    vector<int> v[1000001];
    vector<int> dot[1000001];
    int maxVal = INT_MIN;
    for (auto x : edges) {
        v[x[0]].push_back(x[1]);
        v[x[1]].push_back(x[0]);
        dot[x[0]].push_back(x[1]);
        maxVal = max(x[0], maxVal);
        maxVal = max(x[1], maxVal);
    }

    unordered_map<int, bool> m;
    for (int i = 1; i <= maxVal; i++) m[i] = true;
    for (int i = 1; i <= maxVal; i++) {
        for (auto node : dot[i]) {
            m[node] = false;
        }
    }

    int d;
    for (auto x : m) {
        if (x.second) {
            answer.push_back(x.first);
            d = x.first;
            break;
        }
    }

    for (int i = 1; i <= maxVal; i++) {
        v[i].erase(remove(v[i].begin(), v[i].end(), d), v[i].end());
    }

    set<int> s;
    int donut = 0, stick = 0, eight = 0;
    for (int i = 1; i <= maxVal; i++) {
        if (v[i].size() == 0) {
            s.insert(i);
            continue;
        }
        if (s.count(i) || i == d) continue;

        s.insert(i);
        if (check(v, i, s, i, -1)) {
            set<int> visited;
            if (two(v, i, visited, -1)) {
                eight++;
            } else {
                donut++;
            }
        } else {
            stick++;
        }
    }

    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);

    return answer;
}
