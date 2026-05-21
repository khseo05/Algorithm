//2026.05.21 fail
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (int i=0; i<number.length(); i++) {
        while(k > 0 && !answer.empty() && answer.back() < number[i]) {
            answer.pop_back();
            k--;
        }

        answer.push_back(number[i]);
    }

    while (k > 0) {
        answer.pop_back();
        k--;
    }
    
    return answer;
}