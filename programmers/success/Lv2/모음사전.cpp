//2026.05.02 success
#include <string>
#include <vector>

using namespace std;

void dfs(vector<string>& dir, string word, int len) {
    dir.push_back(word);
    if (len == 5) return;

    char arr[] = {'A', 'E', 'I', 'O', 'U'};
    for (char c : arr) {
        word.push_back(c);
        dfs(dir, word, len+1);
        word.pop_back();
    }
}

int solution(string word) {
    vector<string> dir;
    dfs(dir, "", 0);

    int answer = 0;
    while (true) {
        if (dir[answer] == word) return answer;
        answer += 1;
    }

    return answer;
}
