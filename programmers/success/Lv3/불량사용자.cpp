//2026.05.15 fail
//2026.05.17 fail
//2026.05.18 fail
//2026.05.23 success
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> answer;

bool match(string user, string ban) {
    if (user.length() != ban.length()) return false;

    for (int i=0; i<user.length(); i++) {
        if (ban[i] != '*' && user[i] != ban[i]) return false;
    }

    return true;
}

void dfs(vector<string>& user_id, vector<string>& banned_id, int idx, int mask) {
    if (idx == banned_id.size()) {
        answer.insert(mask);
        return;
    }

    for (int i=0; i<user_id.size(); i++) {
        if (mask & (1 << i)) continue;
        if (!match(user_id[i], banned_id[idx])) continue;

        dfs(user_id, banned_id, idx+1, mask | (1 << i));
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(user_id, banned_id, 0, 0);

    return answer.size();
}
