//2026.06.04 fail
//2026.06.27 success
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> q;
    for (int i=0; i<players.size(); i++) {
        while (!q.empty() && q.front() <= i) {
            q.pop();
        }

        while (q.size() < players[i]/m) {;
            q.push(i+k);
            answer++;
        }
    }

    return answer;
}
