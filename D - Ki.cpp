// https://atcoder.jp/contests/abc138/tasks/abc138_d
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


int N, Q;
int main() {
    cin >> N >> Q;

    vector<vector<int>> graph(N+1);
    vector<long long> value(N+1, 0);

    int a, b;
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 0; i < Q; i++) {
        int p;
        long long x;

        cin >> p >> x;
        value[p] += x;
    }

    vector<int> parent(N+1, -1);
    stack<int> st;

    parent[1] = 0;
    st.push(1);

    while(!st.empty()) {
        int cur = st.top();
        st.pop();

        for (int next: graph[cur]) {
            if (next == parent[cur])
                continue;
            
            parent[next] = cur;
            value[next] += value[cur];

            st.push(next);
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << value[i] << " ";
    }

    return 0;
}