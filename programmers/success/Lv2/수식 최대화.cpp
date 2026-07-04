//2026.07.04 success
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <deque>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<string> v = {"* + -", "* - +", "+ - *", "- + *", "- * +", "+ * -"};

    for (auto pri : v) {
        stringstream ss(pri);
        string token;
        deque<string> priqueue;

        while (ss >> token) {
            priqueue.push_back(token);
        }

        string number;
        deque<string> ex;
        for (auto e : expression)  {
            if (isdigit(e)) number += e;
            else {
                ex.push_back(number);
                ex.push_back({e});
                number = "";
            }
        }
        ex.push_back(number);

        while (!priqueue.empty())  {
            string pri = priqueue.front();
            priqueue.pop_front();

            deque<string> snapex;
            while (!ex.empty()) {
                string n1 = ex.front();
                ex.pop_front();

                if (ex.empty()) {
                    snapex.push_back(n1);
                    break;
                }
                string oper = ex.front();
                ex.pop_front();

                if (pri == oper) {
                    string n2 = ex.front();
                    ex.pop_front();

                    long long val = 0 ;
                    if (oper == "+") {
                        val = stoll(n1) + stoll(n2);
                    } else if (oper == "*") {
                        val = stoll(n1) * stoll(n2);
                    } else  {
                        val = stoll(n1) - stoll(n2);
                    }
                    ex.push_front(to_string(val));
                } else {
                    snapex.push_back(n1);
                    snapex.push_back(oper);
                }
            }
            ex = snapex;
        }
        long long ans = abs(stoll(ex.front()));

        if (ans > answer) answer = ans;
    }
    return answer;
}
