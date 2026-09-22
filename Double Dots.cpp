// https://atcoder.jp/contests/abc168/tasks/abc168_d
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(N + 1, false);
    vector<int> parent(N + 1, -1);

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (visited[next])
                continue;

            visited[next] = true;
            parent[next] = cur;
            q.push(next);
        }
    }

    cout << "Yes\n";

    for (int i = 2; i <= N; ++i) {
        cout << parent[i] << '\n';
    }

    return 0;
}