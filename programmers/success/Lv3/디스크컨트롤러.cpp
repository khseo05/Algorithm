//2026.05.28 success
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int solution(vector<vector<int>> jobs) {
    struct Node {
        int need;
        int request;
        int num;
        
        bool operator<(const Node& other) const {
            if (need == other.need && request == other.request) return num > other.num;
            if (need == other.need) return request > other.request;
            return need > other.need;
        }
    };
    
    priority_queue<Node> pq;
    sort(jobs.begin(), jobs.end());
    
    queue<Node> q;
    for (int i=0; i<jobs.size(); i++) {
        q.push({jobs[i][1], jobs[i][0], i});
    }
    
    int size = jobs.size();
    int stime = 0, etime = 0;
    int answer = 0;
    
    while (!q.empty() || !pq.empty()) {
        while (!q.empty() && q.front().request <= etime) {
            pq.push(q.front());
            q.pop();
        }
        
        if (pq.empty()) {
            etime = q.front().request;
            continue;
        }
        
        int n = pq.top().need;
        int r = pq.top().request;
        pq.pop();
        
        etime += n;
        answer += (etime - r);
    }
    
    return answer/size;
}