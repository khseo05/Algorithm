//2026.05.27 success
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    int n = prices.size();
    for (int i=0; i<n; i++) {
        int sec = 0;
        for (int j=i+1; j<n; j++) {
            sec++;
            if  (prices[i] > prices[j]) break;
        }
        answer.push_back(sec);
    }

    return answer;
}
