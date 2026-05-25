//2026.05.25 success
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    for (int p : priorities) {
        pq.push(p);
    }

    int answer = 0;
    while (!pq.empty()) {
        for (int i=0; i<priorities.size(); i++) {
            if (pq.top() == priorities[i]) {
                pq.pop();
                answer++;

                if (i == location) return answer;
            }
        }
    }
}
