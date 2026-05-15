//2026.05.15 fail
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, bool> check;
int answer = 0;

void dfs(vector<string>& banned_id, unordered_map<string, vector<string>>& m,
    unordered_map<string, bool>& used, vector<string> v, int index = 0) {
    if (index == banned_id.size()) {
        vector<string> temp = v;

        sort(temp.begin(), temp.end());

        string str;
        for (int i=0; i<temp.size(); i++) {
            str += temp[i];
        }

        if (check[str]) return;
        check[str] = true;
        answer += 1;
        return;
    }

    for (auto a : m[banned_id[index]]) {
        if (used[a]) continue;

        v.push_back(a);
        used[a] = true;

        dfs(banned_id, m, used, v, index+1);

        v.pop_back();
        used[a] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    unordered_map<string, vector<string>> m;
    unordered_map<string, bool> used;

    for (string b : banned_id) {
        for (string u : user_id) {
            if (b.length() != u.length()) continue;

            bool Ban = false;
            for (int idx=0; idx<b.length(); idx++) {
                if (b[idx]!='*'&& b[idx]!=u[idx]) {
                    Ban = true;
                    break;
                }
            }

            if (!Ban) m[b].push_back(u);
        }
    }

    vector<string> v;
    dfs(banned_id, m, used, v, 0);

    return answer;
}
