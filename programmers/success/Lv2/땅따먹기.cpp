//2026.09.27 success
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;
    vector<vector<int>> v(land.size(), vector<int>(4, 0));
    
    v[0][0] = land[0][0];
    v[0][1] = land[0][1];
    v[0][2] = land[0][2];
    v[0][3] = land[0][3];
    
    for (int i=1; i<land.size(); i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<4; k++) {
                if (k == j) continue;
                v[i][j] = max(land[i][j] + v[i-1][k], v[i][j]);
            }
        }
    }
    
    answer = max(v[land.size()-1][0], answer);
    answer = max(v[land.size()-1][1], answer);
    answer = max(v[land.size()-1][2], answer);
    answer = max(v[land.size()-1][3], answer);
    
    return answer;
}