//2026.06.21 success
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> v;
    s = s.substr(1, s.size()-2);
    stringstream ss(s);
    string token;

    while (getline(ss, token, '}')) {
        string str = token;
        string word = "";
        for (auto x : str) {
            if (isdigit(x) || x == ',') {
                word += x;
            }
        }
        if (word[0] == ',') word = word.substr(1);
        if (!word.empty()) v.push_back(word);
    }

    sort(v.begin(), v.end(), [](const string& a, const string& b){
        return a.size() < b.size();
    });

    for (auto x : v) {
        stringstream ss(x);
        string token;
        while (getline(ss, token, ',')) {
            auto it = find(answer.begin(), answer.end(), stoi(token));
            if (it == answer.end()) {
                answer.push_back(stoi(token));
            }
        }
    }
    return answer;
}
