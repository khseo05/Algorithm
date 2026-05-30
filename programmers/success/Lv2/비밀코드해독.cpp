//2026.05.30 success
#include <string>
#include <vector>

using namespace std;

void make_case(vector<vector<int>>& v, int max) {
    for (int i=1; i<=max; i++) {
        for (int j=i+1; j<=max; j++) {
            for (int k=j+1; k<=max; k++) {
                for (int m=k+1; m<=max; m++) {
                    for (int n=m+1; n<=max; n++) {
                        v.push_back({i, j, k, m, n});
                    }
                }
            }
        }
    }
}

void pruning(vector<vector<int>>& v, vector<vector<int>> q, vector<int> ans, int idx) {
    vector<vector<int>> p;

    for (auto x : v) {
        int cnt = 0;
        for (int i : x ) {
            for (int j=0; j<q[idx].size(); j++) {
                if (i == (q[idx][j])) {
                    cnt++;
                    break;
                }
            }
        }

        if (cnt == ans[idx]) p.push_back(x);
    }

    v = p;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    vector<vector<int>> v;
    make_case(v, n);

    for (int i=0; i<ans.size(); i++) {
        pruning(v, q, ans, i);
    }

    return v.size();
}
