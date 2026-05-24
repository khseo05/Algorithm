//2026.05.03 fail
//2026.05.23 success
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

extern string submit(int);

void isMatch(string& hint, string& h, vector<string>& ans) {
    vector<string> v;
    for (string a : ans) {
        int strike = 0;
        int ball = 0;
        for (int i = 0; i < 4; i++) {
            if (h[i] == a[i]) {
                strike++;
            }   else {
                    for (int j=0; j < 4; j++) {
                    if (i==j) continue;
                    if (h[j] == a[i]) {
                        ball++;
                        break;
                    }
                }
            }
        }

        string str = to_string(strike)+"S " + to_string(ball) +"B";
        if (str == hint) {
            v.push_back(a);
        }
    }

    ans = v;
}

void makeCase(vector<string>& ans) {
    for (int i=1; i<=9; i++) {
        for (int j=0; j<=9; j++) {
            if (j==i) continue;
            for (int k=0; k<=9; k++) {
                if (k==j || k==i) continue;
                for (int l=0; l<=9; l++) {
                    if (l==k || l==j || l==i) continue;
                    string a;
                    a += to_string(i) + to_string(j) + to_string(k) + to_string(l);
                    ans.push_back(a);
                }
            }
        }
    }
}

void compareCnt(string& h, vector<string>& ans) {
    int cnt = 999999;
    for (string compare : ans) {
        int worst = 0;
        unordered_map<string, int> m;

        for (string target : ans) {
            int strike = 0;
            int ball = 0;
            for (int i = 0; i < 4; i++) {
                if (compare[i] == target[i]) {
                    strike++;
                }   else {
                        for (int j=0; j < 4; j++) {
                        if (i==j) continue;
                        if (compare[j] == target[i]) {
                            ball++;
                            break;
                        }
                    }
                }
            }

            string s = to_string(strike) + to_string(ball);
            m[s]++;
        }

        for (auto& x : m) {
            worst = max(worst, x.second);
        }

        if (cnt > worst) {
            h = compare;
            cnt = worst;
        }
    }
}

int solution(int n) {
    vector<string> ans;
    makeCase(ans);

    string h = "1234";
    string hint;
    while (!ans.empty()) {
        hint = submit(stoi(h));
        if (hint == "4S 0B") return stoi(h);
        isMatch(hint, h, ans);
        ans.erase(remove(ans.begin(), ans.end(), h), ans.end());
        if (ans.empty()) break;
        if (ans.size() == 1) return stoi(ans[0]);
        compareCnt(h, ans);
    }

    return stoi(h);
}
