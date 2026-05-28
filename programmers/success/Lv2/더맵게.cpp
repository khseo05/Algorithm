//2026.05.28 success
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0;
    
    for (int sco : scoville) {
        pq.push(sco);
    }
    
    while (true) {
        if (pq.top() >= K) return answer;
        if (pq.size() < 2) return -1;
        
        int first = pq.top();
        pq.pop();
        int sec = pq.top();
        pq.pop();
        
        pq.push(first + (sec * 2));
        
        answer++;
    }
    
    return answer;
}