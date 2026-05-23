//2026.05.21 fail
//2026.05.23 success
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    answer.push_back(number[0]);

    int cnt = 0;
    for (int i=1; i<number.length(); i++) {
        while (!answer.empty() && number[i] > answer.back() && cnt < k) {
            answer.pop_back();
            cnt++;
        }
        answer.push_back(number[i]);
    }

    while (cnt < k) {
        answer.pop_back();
        cnt++;
    }

    return answer;
}
