//2026.06.22 success
#include <string>
#include <set>
#include <tuple>
using namespace std;

int solution(string dirs) {
    set<tuple<int,int,int,int>> s;

    int x = 0, y = 0;
    for (auto d : dirs) {
        int nx = x, ny = y;
        if (d == 'U') ny += 1;
        else if (d == 'D') ny -= 1;
        else if (d == 'R') nx += 1;
        else nx -= 1;

        if (nx < -5 || nx > 5 || ny < -5 || ny > 5) continue;

        s.insert({x, y, nx, ny});
        s.insert({nx, ny, x, y});

        x = nx; y = ny;
    }

    return s.size() / 2;
}
