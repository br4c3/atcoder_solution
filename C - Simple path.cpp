// https://atcoder.jp/contests/abc270/tasks/abc270_c
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    int N, X, Y;
    cin >> N >> X >> Y;

    int u, v;
    vector<vector<int>> graph(N + 1);
    for (int i = 1; i < N; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> parent(N + 1, -1);
    vector<bool> visited(N + 1, false);
    visited[X] = true;

    stack<int> st;
    st.push(X);
    while (!st.empty()) {
        int cur = st.top();
        st.pop();

        for (int next : graph[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            parent[next]  = cur;
            st.push(next);
        }
    }

    vector<int> path;

    int cur = Y;
    while (cur != -1) {
        path.push_back(cur);

        if (cur == X)
            break;
        
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    for (int node: path) {
        cout << node << ' ';
    }

    return 0;
}