//2026.09.27 fail
//2026.10.01 success
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct st {
    int val;
    int idx;
};

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<st> s;

    for (int i=0; i<numbers.size(); i++) {
        while (!s.empty() && s.top().val < numbers[i]) {
            answer[s.top().idx] = numbers[i];
            s.pop();
        }
        
        if (i+1 < numbers.size() && numbers[i] < numbers[i+1]) answer[i] = numbers[i+1];
        else {
            s.push({numbers[i], i});
        }
    }
    
    return answer;
}