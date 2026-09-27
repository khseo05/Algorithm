//2026.09.27 성ㅇ공
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s1, s2;
    
    for (int i=order.size(); i>0; i--) s1.push(i);
    for (auto x : order) {
        while (true) {
            if (s1.empty() && s2.empty()) return answer;
            if (s1.empty() && !s2.empty() && s2.top() != x) return answer;
            if (!s1.empty() && s1.top() == x) {
                s1.pop();
                answer++;
                break;
            }  else if (!s2.empty() && s2.top() == x) {
                s2.pop();
                answer++;
                break;
            } 
            
            s2.push(s1.top());
            s1.pop();
        }
    }
    return answer;
}