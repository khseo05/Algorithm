//2026.06.30 fail
#include <string>
#include <vector>
#include <stack>

using namespace std;

void convert(string& str) {
    if (str.size() == 0) return;
    
    string word = str.substr(1, str.size()-2);
    for (char& c : word) c = (c == '(') ? ')' : '(';
    
    str = "(" + word + ")";
}

bool correct(string str) {
    int balance = 0;
    for (char c : str) {
        if (c == '(') balance++;
        else balance--;
        if (balance < 0) return false;
    }
    return true;
}

string solution(string p) {
    string answer = "";
    stack<char> open;
    stack<char> close;
    string str = "";
    for (int i=0; i<p.size(); i++) {
        if (open.size() == close.size() && open.size() != 0) {
            if (str.front() == '(' && correct(str)) answer += str;
            else {
                convert(str);
                answer += str;
            }
            str = "";
            open = stack<char>();
            close = stack<char>();
        }
        
        if (p[i] == '(') open.push(p[i]);
        if (p[i] == ')') close.push(p[i]);
        str += p[i]; 
    }
    
    if (!str.empty()) {
        if (correct(str)) answer += str;
        else {
            convert(str);
            answer += str;
        }
    }
    return answer;
}