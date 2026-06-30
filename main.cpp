//2026.06.30 success
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0;
    queue<long long> q1;
    for (auto x : queue1) {
        sum1 += x;
        q1.push(x);
    }
    
    long long sum2 = 0;
    queue<long long> q2;
    for (auto x : queue2) {
        sum2 += x;
        q2.push(x);
    }
    
    for (long long i=0; i<= queue1.size() * 2 + 2; i++) {
        if (sum1 == sum2) return i;
        if (sum1 > sum2) {
            long long val = q1.front();
            q1.pop();
            q2.push(val);
            sum2 += val;
            sum1 -= val; 
        } else if (sum1 < sum2) {
            long long val = q2.front();
            q2.pop();
            q1.push(val);
            sum1 += val;
            sum2 -= val;
        }
    }
    
    
    return -1;
}