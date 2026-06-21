//2026.06.21 success
#include <iostream>
using namespace std;

int solution(int n) {
    int ans = 0;

    while (true) {
        if (n == 0) return ans;
        if (n%2 == 0) n /= 2;
        else {
            n -= 1;
            ans += 1;
        }
    }
    return ans;
}
