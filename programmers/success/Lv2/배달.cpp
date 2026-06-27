//2026.06.27 success
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 1;

    vector<pair<int, int>> graph[N+1];
    for (int i=0; i<road.size(); i++) {
        int first = road[i][0];
        int second = road[i][1];
        int cost = road[i][2];

        graph[first].push_back({second, cost});
        graph[second].push_back({first, cost});
    }

    vector<int> dist(N+1, INT_MAX);
    dist[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (cost > dist[u]) continue;

        for (int i=0; i<graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i=2; i<=N; i++) {
        if (dist[i] <= K) answer++;
    }

    return answer;
}
