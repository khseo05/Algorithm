// 2026.09.25 success
#include <iostream>
#include <cmath>

using namespace std;

void judge(int& n) {
    if (n%2!=0) {
        n += 1;
    }
    n /= 2;
}

int solution(int n, int a, int b) {
    int answer = 0;
    while (a != b) {
        judge(a);
        judge(b);
        
        answer++;
    }
    
    return answer;
}