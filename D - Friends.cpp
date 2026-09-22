// https://atcoder.jp/contests/abc177/tasks/abc177_d
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    int a, b;
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(N + 1, false);
    stack<int> st;

    int ans = 0;
    
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            st.push(i);
            visited[i] = true;

            int cnt = 0;

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

            ans = max(ans, cnt);
        }
    }

    cout << ans;

    return 0;
}