//2026.10.03 실패
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int binary(vector<int> v, int n) {
    int s = 0, e = v.size() - 1, ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (v[mid] < n) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

bool divide(vector<int> v, int n, int idx) {
    for (int i = idx; i < v.size(); i++) {
        if (v[i] % n != 0) return false;
    }
    return true;
}

bool nodivide(vector<int> v, int n, int idx) {
    for (int i = idx; i < v.size(); i++) {
        if (v[i] % n == 0) return false;
    }
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());

    for (int i = arrayA.size() - 1; i >= 0; i--) {
        int idx = binary(arrayB, arrayA[i]) + 1;
        if (divide(arrayA, arrayA[i], 0) && nodivide(arrayB, arrayA[i], idx)) {
            answer = max(arrayA[i], answer);
            break;
        }
    }

    for (int i = arrayB.size() - 1; i >= 0; i--) {
        int idx = binary(arrayA, arrayB[i]) + 1;
        if (divide(arrayB, arrayB[i], 0) && nodivide(arrayA, arrayB[i], idx)) {
            answer = max(arrayB[i], answer);
            break;
        }
    }

    return answer;
}