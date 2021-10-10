//
// Created by 走线大师 on 2021/10/10.
//

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e4 + 5;
int L[MAXN], R[MAXN], N, dp[MAXN][2];
int path(int start, int i, int order) {
    if (start <= L[i]) {
        if (order == 0) return R[i] - start + R[i] -  L[i];
        else return R[i] - start;
    } else if (start < R[i]) {
        if (order == 0) return R[i] - L[i] + R[i] - start;
        else return R[i] - L[i] + start - L[i];
    } else {
        if (order == 0) return start - L[i];
        else return start - L[i] + R[i] - L[i];
    }
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];
    dp[1][0] = R[1] - 1 + R[1] - L[1], dp[1][1] = R[1] - 1;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = 1 + min(dp[i-1][0] + path(L[i-1], i, 0), dp[i-1][1] + path(R[i-1], i, 0));
        dp[i][1] = 1 + min(dp[i-1][0] + path(L[i-1], i, 1), dp[i-1][1] + path(R[i-1], i, 1));
    }
    cout << min(dp[N][0] + N - L[N], dp[N][1] + N - R[N]) << endl;
}