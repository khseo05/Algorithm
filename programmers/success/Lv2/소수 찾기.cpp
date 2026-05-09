//2026.05.04 success
//2026.05.09 success
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

vector<int> w;
unordered_map<int, bool> m;

void dfs(vector<bool>& v, string numbers, string& s) {
    for (int i=0; i<numbers.length(); i++) {
        if (v[i]) continue;
        v[i] = true;
        s += numbers[i];
        int n = stoi(s);

        if (!m[n]) {
            m[n] = true;
            w.push_back(n);
        }

        dfs(v, numbers, s);

        v[i] = false;
        s.pop_back();
    }
}

int solution(string numbers) {
    vector<bool> v(numbers.length(), false);

    string s = "";
    dfs(v, numbers, s);

    int answer = 0;
    for (int n : w) {
        if (n==0 || n==1) continue;

        bool check = false;
        for (int i=2; i<=sqrt(n); i++) {
            if (n%i==0) {
                check = true;
                break;
            }
        }

        if (!check) answer += 1;
    }

    return answer;
}
