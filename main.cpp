#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N+1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<int> B(M+1);
    for (int i = 1; i <= M; ++i) {
        cin >> B[i];
    }
    
    int min = INT_MAX;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            int tmp = abs(A[i]-B[j]);
            if (min > tmp) {
                min = tmp;
            }
        }
    }

    cout << min;

    return 0;
}