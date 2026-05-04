//2026.05.04 success
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

void dfs(vector<int>& v, vector<bool>& visited, string num, string numbers) {
    for (int i=0; i<numbers.length(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        num.push_back(numbers[i]);
        v.push_back(stoi(num));
        dfs(v, visited, num, numbers);
        num.pop_back();
        visited[i] = false;
    }
}

int solution(string numbers) {
    vector<int> v;
    vector<bool> visited(numbers.length(), false);
    dfs(v, visited, "", numbers);

    int answer = 0;
    map<int , bool> m;

    for (int i=0; i<v.size(); i++) {
        if (m[v[i]]) continue;
        if (v[i] == 0 || v[i] == 1) continue;
        bool isPrime = true;
        for (int j=2; j <= sqrt(v[i]); j++) {
            if (v[i]%j==0) isPrime = false;
        }

        m[v[i]] = true;
        if (isPrime) answer += 1;
    }

    return answer;
}