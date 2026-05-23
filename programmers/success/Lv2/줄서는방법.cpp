//2026.05.23 success
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;

    for (int i=1; i<=n; i++) {
        v.push_back(i);
    }

    long long fac = 1;
    for (int i=2; i<n; i++) {
        fac *= i;
    }

    k--;
    for (int i=n; i>0; i--) {
        int idx = k / fac;
        answer.push_back(v[idx]);
        v.erase(v.begin() + idx);

        if (i > 1) {
            k %= fac;
            fac /= (i-1);
        }
    }
    return answer;
}
