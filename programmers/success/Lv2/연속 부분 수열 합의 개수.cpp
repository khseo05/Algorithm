//2026.9.27 fail
//2026.10.01 fail
//2026.10.12 실패
//2026.10.18 성공
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> s;
    
    for (int i=1; i<=elements.size(); i++) {
        int sum = 0;
        for (int j=0; j<i; j++) sum += elements[j];
        s.insert(sum);
        
        for (int start = 1; start < elements.size(); start++) {
            sum += elements[(start + i -1) % elements.size()] - elements[start-1];
            s.insert(sum);
        }
    }
    
    return s.size();
}