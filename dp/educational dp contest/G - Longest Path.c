// https://atcoder.jp/contests/dp/tasks/dp_g
#include <stdio.h>
#include <string.h>

#define MAXN 100005
#define MAXM 100005

typedef struct {
    int to;
    int next;
} Edge;

int N, M;

int head[MAXN];
Edge edges[MAXM];
int edge_count = 0;

int dp[MAXN];

void add_edge(int from, int to) {
    edges[edge_count].to = to;
    edges[edge_count].next = head[from];
    head[from] = edge_count++;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(int cur) {
    if (dp[cur] != -1)
        return dp[cur];

    dp[cur] = 0;

    for (int e = head[cur]; e != -1; e = edges[e].next) {
        int next = edges[e].to;
        dp[cur] = max(dp[cur], dfs(next) + 1);
    }

    return dp[cur];
}

int main(void) {
    scanf("%d %d", &N, &M);

    memset(head, -1, sizeof(head));
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < M; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        add_edge(x, y);
    }

    int ans = 0;

    for (int i = 1; i <= N; ++i) {
        ans = max(ans, dfs(i));
    }

    printf("%d\n", ans);

    return 0;
}