//2026.05.15 fail
//2026.05.17 fail
//2026.05.18 fail
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> s;

bool match(string u, string b) {
    if (u.length() != b.length()) return false;


    for (int i=0; i<u.length(); i++) {
        if (b[i] != '*' && u[i] != b[i]) return false;
    }

    return true;
}

void dfs(vector<string>& user_id, vector<string>& banned_id, int mask, int idx) {
    if (idx == banned_id.size()) {
        s.insert(mask);
        return;
    }

    for (int i=0; i<user_id.size(); i++) {
        if (mask & (1 << i)) continue;
        if (!match(user_id[i], banned_id[idx])) continue;

        dfs(user_id, banned_id, mask | (1 << i), idx+1);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(user_id, banned_id, 0, 0);
    return s.size();
}
