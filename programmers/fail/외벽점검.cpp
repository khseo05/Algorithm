//2026.05.25 fail
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int answer = 1e9;
set<int> se;

void dfs(int mask, vector<int> dist, vector<pair<int,bool>>& v, vector<int> weak) {
    if (mask >=  (1 << dist.size())) return;

    bool allCheck = false;
    for (auto x: v) {
        if (x.second == false) {
            allCheck = true;
            break;
        }
    }
    if (!allCheck) {
        int cnt = 0;
        for (int i=0; i<dist.size(); i++) {
            if (mask & (1 << i)) cnt++;
        }

        se.insert(mask);
        answer = min(answer, cnt);
    }

    for (int s : se) {
        if ((mask & s) == s) {
            return;
        }
    }

    for (int i=0; i<dist.size(); i++) {
        if (mask & (1 << i)) continue;

        int d = dist[i];

        for (int j=0; j<v.size(); j++) {
            if (v[j].second) continue;

            if (d+j-1> v.size()) {
                for (int k=j; k<v.size(); k++) v[k].second = true;
                for (int l=0; l<v.size() - (d+j-1); l++) v[l].second = true;

                dfs(mask | (1 << i), dist, v, weak);

                for (int k=j; k<v.size(); k++) {
                    for (int w : weak) {
                        if (k==w-1) v[k].second = false;
                    }
                }
                for (int l=0; l<v.size() - (d+i-1); l++) {
                    for (int w : weak) {
                        if (l==w-1) v[l].second = false;
                    }
                }
            } else {
                for (int k=j, l=d; l>0; k++, l--) v[k].second = true;

                dfs(mask | (1 << i), dist, v, weak);

                for (int k=j, l=d; l>0; k++, l--) {
                    for (int w : weak) {
                        if (k==w-1) v[k].second = false;
                    }
                }
            }
        }
    }

    return;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    vector<bool> b(dist.size(), false);
    vector<pair<int, bool>> v(n, {0, true});
    for (int i : weak) {
        v[i-1].first = 1;
        v[i-1].second = false;
    }

    dfs(0, dist, v, weak);

    return answer == 1e9 ? -1 : answer;
}
