//2026.05.23 fail
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    for (char n : name) {
        answer = min(n - 'A', 'Z' - n + 1) + answer;
    }

    int minMove = name.length()-1;
    for (int i=0; i<name.length(); i++) {
        int j = i+1;
        while (name[j] == 'A' && j < name.length()) j++;

        int priorLeft = i + i + (name.length() - j);
        int priorRight = (name.length() - j) + (name.length() - j) + i;
        
        minMove = min({priorLeft, priorRight, minMove});
    }

    return answer + minMove;
}