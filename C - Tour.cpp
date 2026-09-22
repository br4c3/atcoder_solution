// https://atcoder.jp/contests/abc204/tasks/abc204_c
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    int a, b;
    vector<vector<int>> graph(N+1);
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<bool> visited(N+1);
    stack<int> st;

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        fill(visited.begin(), visited.end(), false);

        int cnt = 0;
        st.push(i);
        visited[i] = true;

        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            cnt++;

            for (int next : graph[cur]) {
                if (visited[next]) continue;

                st.push(next);
                visited[next] = true;
            }
        }
        ans += cnt;
    }

    cout << ans;

    return 0;
}