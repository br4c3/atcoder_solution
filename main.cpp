#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

typedef struct {
    int to;
    long long cost;
} Edge;


int N;
int main(void) {
    cin >> N;
    
    vector<vector<Edge>> graph(N+1);
    long long a, b;
    int x;
    for (int i = 1; i < N; ++i) {
        cin >> a >> b >> x;
        graph[i].push_back({i+1, a});
        graph[i].push_back({x, b});
    }

    vector<long long> dist(N+1, LLONG_MAX);

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;
    
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost > dist[cur])
            continue;

        for (Edge next : graph[cur]) {
            int new_cost = cost + next.cost;
            dist[]
            next.cost;
            next.to;
        }
    }

    return 0;
}