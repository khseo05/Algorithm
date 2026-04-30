#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> v(101);
    v[1] = 1;
    v[2] = 1;
    v[3] = 1;
    v[4] = 2;
    v[5] = 2;

    for (int i=6; i<101; i++) {
        v[i] = v[i-1] + v[i-5];
    }

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        cout << v[a] << "\n";
    }
}

/*
1       1
1       2
1       3
2 (1+1) 4 
2 (2)   5
3 (1+2) 6 1 5   4
4 (1+3) 7 2 6   4
5 (1+4) 8 3 7   4
7 (5+2) 9 5 8 4
9 (2+7) 10 5 9 4
12 (3+9)11 6 10 4 
16 (4+12)12 7 11 4
21 (5+16)13 8 12 4 

*/