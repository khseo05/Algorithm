//2026.10.03 실패
//2026.10.12 성공
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcdA = arrayA[0], gcdB = arrayB[0];
    
    for (auto x : arrayA) gcdA = gcd(gcdA, x);
    for (auto x : arrayB) gcdB = gcd(gcdB, x);
    
    for (auto x : arrayB) {
        if (x % gcdA == 0) {
            gcdA = 0;
            break;
        }
    }
    
    for (auto x : arrayA) {
        if (x % gcdB == 0) {
            gcdB = 0;
            break;
        }
    }
    
    return max(gcdA, gcdB);
}