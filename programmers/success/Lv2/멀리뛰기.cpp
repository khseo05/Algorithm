//2026.09.26 success
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> v(2001);
    v[1] = 1 % 1234567;
    v[2] = 2 % 1234567;
    for (int i=3; i <= n; i++) {
        v[i] = (v[i-1] + v[i-2]) % 1234567;
    }
    
    answer = v[n];
    
    return answer;
}