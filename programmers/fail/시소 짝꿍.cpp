//2026.10.02 실패
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<long long, vector<long long>> m;
    unordered_map<long long, long long> cnt;
    unordered_map<long long, bool> b;
    
    for (auto w : weights) cnt[w]++;
    
    for (auto w : weights) {
        m[w*2].push_back(w);
        m[w*3].push_back(w);
        m[w*4].push_back(w);
    }
    
    for (auto x : m) {
        long long size = x.second.size();
        answer += (size * (size-1)) / 2;
    }
    
    for (auto x : cnt) {
        answer += x.second * (x.second-1) / 2;
    }
    
    return answer;
}