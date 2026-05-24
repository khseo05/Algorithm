//2026.05.24 success
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int weight;
    int count = 0;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int w = truck_weights[0];

    queue<Node> q;
    q.push({truck_weights[0], 0});

    truck_weights.erase(truck_weights.begin());

    while (!q.empty()) {
        if (q.front().count >= bridge_length) {
            w -= q.front().weight;
            q.pop();
        }

        if (truck_weights.size() != 0 && w + truck_weights[0] <= weight) {
            w += truck_weights[0];
            q.push({truck_weights[0], 0});
            truck_weights.erase(truck_weights.begin());
        }

        int size = q.size();
        for (int i=0; i<size; i++) {
            int weight = q.front().weight;
            int count = q.front().count + 1;
            q.pop();
            q.push({weight, count});
        }

        answer++;
    }

    return answer;
}
