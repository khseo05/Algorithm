//2026.05.08 success
#include <string>
#include <vector>

using namespace std;

vector<int> answer;
vector<int> ryan(11, 0);
int maxDiff;

bool isBetter(vector<int> a, vector<int>& b) {
    for (int i = 10; i >= 0; i--) {
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return false;
}

void dfs(int idx, int remain, vector<int> info) {
    if (idx == 11 || remain == 0) {
        ryan[10] += remain;
        
        int apeach = 0, lion = 0;
        for (int i = 0; i < 11; i++) {
            if (info[i] == 0 && ryan[i] == 0) continue;
            if (ryan[i] > info[i]) lion += (10 - i);
            else apeach += (10 - i);
        }
        
        int diff = lion - apeach;
        if (diff > 0) {
            if (diff > maxDiff || (diff == maxDiff && isBetter(ryan, answer))) {
                maxDiff = diff;
                answer = ryan;
            }
        }
        
        ryan[10] -= remain;
        return;
    }
    
    if (remain > info[idx]) {
        ryan[idx] = info[idx] + 1;
        dfs(idx + 1, remain - info[idx] - 1, info);
        ryan[idx] = 0;
    }
    
    ryan[idx] = 0;
    dfs(idx + 1, remain, info);
}

vector<int> solution(int n, vector<int> info) {
    maxDiff = 0;
    
    dfs(0, n, info);
    
    if (maxDiff == 0) return {-1};
    return answer;
}