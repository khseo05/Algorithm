//2026.05.26 fail
#include <vector>
#include <set>
using namespace std;

set<int> answer;

void dfs(vector<int>& a, bool used) {
    if (a.size() == 1) {
        answer.insert(a[0]);
        return;
    }

    for (int i = 0; i < (int)a.size() - 1; i++) {
        int kill = (a[i] > a[i+1]) ? i : i+1;
        int value = a[kill];
        a.erase(a.begin() + kill);
        dfs(a, used);
        a.insert(a.begin() + kill, value);

        if (!used) {
            int kill = (a[i] < a[i+1]) ? i : i+1;
            int value = a[kill];
            a.erase(a.begin() + kill);
            dfs(a, true);
            a.insert(a.begin() + kill, value);
        }

    }
}

int solution(vector<int> a) {
    answer.clear();
    dfs(a, false);
    return answer.size();
}
