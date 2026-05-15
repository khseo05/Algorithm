//2026.05.15 success
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());

    int answer = 0;
    int a = 0;
    int b = people.size()-1;
    while (a <= b) {
        if (a == b) {
            answer++;
            break;
        }

        if (people[a] + people[b] <= limit) {
            a++;
            b--;
            answer++;
        } else if (people[a] + people[b] > limit) {
            b--;
            answer++;
            continue;
        }

    }
    return answer;
}
