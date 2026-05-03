//2026.05.02 fail
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

void dfs(vector<int>& list, vector<bool>& check, string numbers, string num) {
    for (int i=0; i<numbers.length(); i++) {
        if (check[i]) continue;
        check[i] = true;
        num += numbers[i];
        list.push_back(stoi(num));
        dfs(list, check, numbers, num);
        num.pop_back();
        check[i] = false;
    }
}

int solution(string numbers) {
    vector<int> list;
    vector<bool> check(numbers.length(), false);
    dfs(list, check, numbers, "");

    unordered_map<int, bool> m;
    int answer = 0;
    for (int i : list) {
        if (i == 0 || i == 1) continue;

        if (m[i]) continue;
        bool isPrime = true;
        for (int j=2; j<=sqrt(i); j++) {
            if (i%j == 0) isPrime = false;
        }

        m[i] = true;
        if (isPrime) answer += 1;
    }

    return answer;
}
