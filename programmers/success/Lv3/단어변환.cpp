//2026.05.02 success
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    bool check = false;
    for (int i=0; i<words.size(); i++) {
        if (words[i] == target) check = true;
    }
    if (!check) return 0;

    struct Node {
        string word;
        int count;
    };

    queue<Node> q;
    q.push({begin, 0});

    unordered_map<string, bool> m;
    m[begin] = true;

    while (!q.empty()) {
        string word = q.front().word;
        int cnt = q.front().count;
        q.pop();
        m[word] = true;

        if (word == target) return cnt;

        for (int i=0; i<word.length(); i++) {
            for (char c='a'; c<='z'; c++) {
                string w = word;
                w[i] = c;
                for (int i=0; i<words.size(); i++) {
                    if (w == words[i] && !m[w]) {
                        q.push({w, cnt+1});
                    }
                }
            }
        }
    }
}
