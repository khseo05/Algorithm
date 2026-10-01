//2026.10.01 성공
#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    vector<int> v;
    
    while (storey > 0) {
        v.push_back(storey % 10);
        storey /= 10;
    }
    
    bool ce = false;
    for (int i=0; i<v.size(); i++) {
        if (ce) {
            ce = false;
            v[i]++;
        }
        
        if (v[i] > 5 || (v[i] == 5 && i+1 < v.size() && v[i+1] >= 5)) {
            ce = true;
            answer += 10 - v[i];
        } else answer += v[i];
    }
    
    if (ce) answer++;
    
    return answer;
}