//2026.06.27 fail
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

int dfs(vector<int>& q1, vector<int>& q2, int sum1, int sum2, int answer) {
    if (sum1 == sum2) return answer;

    if (q1.size() != 0) {
        int front = q1[0];
        q1.erase(q1.begin());
        q2.push_back(front);
        sum1 -= front;
        sum2 += front;
        answer++;
        dfs(q1, q2, sum1, sum2, answer);
    }

    dfs(q2, q1, sum2, sum1, answer);
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int sum1 = 0;
    for (int q1 : queue1) {
        sum1 += q1;
    }

    int sum2 = 0;
    for (int q2 : queue2) {
        sum2 += q2;
    }

    dfs(queue1, queue2, sum1, sum2, answer);

    return answer;
}
