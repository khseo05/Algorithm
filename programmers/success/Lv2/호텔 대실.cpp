//2026.10.03 성공
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int tosec(string s) {
    return stoi(s.substr(0, 2))*60*60 + stoi(s.substr(3, 2))*60;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<int> v(90000, 0);
    
    for (auto x : book_time) {
        int s = tosec(x[0]);
        int e = tosec(x[1]) + 600;
        
        for (int i=s; i<e; i++) {
            v[i]++;
        }
    }
    
    for (auto x : v) {
        answer = max(x, answer);
    }
    
    return answer;
}