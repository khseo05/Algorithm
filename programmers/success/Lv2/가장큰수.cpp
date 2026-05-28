//2026.05.28 success
#include <string>
#include <vector>
#include <algorithm>.

using namespace std;

string solution(vector<int> numbers) {
    vector<string> num;
    for (int i=0; i<numbers.size(); i++) {
        num.push_back(to_string(numbers[i]));
    }
    
    sort(num.begin(), num.end(), [](string& a, string& b) {
        return a + b > b + a;
    });
    
    if (num[0] == "0") return "0";

    string answer = "";
    for (string s : num)  {
        answer += s;
    }
    
    return answer;
}