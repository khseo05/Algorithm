//2026.06.22 success
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s;
    while (n > 0) {
        int res = n % k;
        n /= k;
        s = to_string(res) + s;
    }

    stringstream ss(s);
    string token;
    while (getline(ss, token, '0')) {
        if (!token.empty() && isPrime(stoll(token))) answer++;
    }

    return answer;
}
