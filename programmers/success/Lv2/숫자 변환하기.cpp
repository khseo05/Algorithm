//2026.09.29 success
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct st {
    int num;
    int cnt;
};

int solution(int x, int y, int n) {
    if (x == y) return 0;
    
    unordered_map<int, bool> m;
    queue<st> q;
    q.push({x+n, 1});
    q.push({x*2, 1});
    q.push({x*3, 1});
    m[x+n] = true;
    m[x*2] = true;
    m[x*3] = true;
    
    while (!q.empty()) {
        int number = q.front().num;
        int count = q.front().cnt;
        q.pop();
        
        if (number == y) return count;
        
        if (number+n <= y && !m[number+n]) {
            q.push({number+n, count+1});
            m[number+n] = true;
        }
        
        if (number*2 <= y && !m[number*2]) {
            q.push({number*2, count+1});
            m[number*2] = true;
        }
        if (number*3 <= y && !m[number*3]) {
            q.push({number*3, count+1});
            m[number*3] = true;
        }
    }
    
    return -1;
}