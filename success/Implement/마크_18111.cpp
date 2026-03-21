//2026.03.21 구현 보완형 성공

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, b;
    cin >> n >> m >> b;

    int high = INT_MIN, low = INT_MAX;

    vector<vector<int>> v (n, vector(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int a;
            cin >> a;
            v[i][j] = a;
            high = max(a, high);
            low = min(a, low);
        }
    }

    int ansh = low, anst = INT_MAX;
    for (int i=low; i<=high; i++) {
        int bag = b;
        int height = i;
        int time = 0;
        bool check = true;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (v[i][j] > height) {
                    time += (v[i][j] - height)*2;
                    bag += v[i][j] - height;
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (v[i][j] < height) {
                    time += height - v[i][j];
                    bag -= height - v[i][j];

                    if (bag < 0) {
                        check = false;
                        break;
                    }
                }
            }
        }

        if (check && anst > time)  {
            anst = time;
            ansh = height;
        }

        if (check && anst == time) {
            ansh = height;
        }
    }
    
    cout << anst << " " << ansh;
}

// 제거 2초, 설치 1초