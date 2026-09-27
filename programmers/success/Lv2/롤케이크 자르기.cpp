//2026.09.27 success
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> leftm;
    unordered_map<int, int> rightm;
    
    for (auto x : topping) rightm[x]++;
    
    for (int i=0; i<topping.size()-1; i++) {
        leftm[topping[i]]++;
        rightm[topping[i]]--;
        if (rightm[topping[i]] == 0) rightm.erase(topping[i]);
        
        if (leftm.size() == rightm.size()) answer++;
    }
    return answer;
}