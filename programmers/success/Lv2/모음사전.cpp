//2026.05.02 success
//2026.05.09 success
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;

void dfs(string w, int& cnt) {
    if (w.length() == 5) return;

    char arr[] = {'A', 'E', 'I', 'O', 'U'};
    for (char s : arr) {
        w.push_back(s);
        m[w] = ++cnt;
        dfs(w, cnt);
        w.pop_back();
    }
}

int solution(string word) {
    int cnt = 0;
    dfs("", cnt);
    return m[word];
}
