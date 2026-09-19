// https://atcoder.jp/contests/dp/tasks/dp_b
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    const int INF = 1e9;
    vector<int> dp(N, INF);
    dp[0] = 0;

    for (int i = 1; i < N; ++i) {
        for (int k = 1; k <= K; ++k) {
            if (i - k < 0) break;

            dp[i] = min(dp[i], dp[i-k] + abs(h[i] - h[i-k]));
        }
    }

    cout << dp[N-1] << '\n';

    return 0;
}