// https://atcoder.jp/contests/dp/tasks/dp_d
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, W;
    scanf("%d %d", &N, &W);

    int weight, value;
    long long* dp = calloc(W + 1, sizeof(long long));
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &weight, &value);
        for (int w = W; w >= weight; w--) {
            long long tmp = dp[w - weight] + value;

            if (tmp > dp[w]) {
                dp[w] = tmp;
            }
        }
    }

    printf("%lld\n", dp[W]);

    free(dp);

    return 0;
}
