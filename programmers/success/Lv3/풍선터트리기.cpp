//2026.05.26 fail
//2026.06.14 success
#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    int answer = 0;

    vector<int> left_min(n, INT_MAX);
    for (int i = 1; i < n; i++)
        left_min[i] = min(left_min[i-1], a[i-1]);

    vector<int> right_min(n, INT_MAX);
    for (int i = n-2; i >= 0; i--)
        right_min[i] = min(right_min[i+1], a[i+1]);

    for (int i = 0; i < n; i++) {
        if (a[i] <= left_min[i] || a[i] <= right_min[i])
            answer++;
    }

    return answer;
}
