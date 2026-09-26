//2026.09.26 success
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int first = arr.front();
    int answer = arr.front();
    
    for (int i=1; i<arr.size(); i++) {
        answer = lcm(answer, (long long) arr[i]);
    }

    return answer;
}