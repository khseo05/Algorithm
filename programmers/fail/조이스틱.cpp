//2026.05.20 fail
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    for (int i=0; i<name.length(); i++) {
        answer = min(name[i] - 'A', 'Z' - name[i] + 1) + answer;
    }

    int cnt = 0;
    for (char n : name) {
        if (n == 'A') cnt++;
    }

    name[0] = 'A';
    while(true) {
        int left = 0;
        int right = 0;

        
    }

    return answer;
}