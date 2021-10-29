//
// Created by Shaw on 2021/10/15.
//

#include <bits/stdc++.h>

using namespace std;
// dp[i][j] 前i个数第一维度为j的第二维度和最大值
// ans = max(dp[N][j] + j) (j >= 0 且dp[N][j] > 0)
// dp[i][j] = max(dp[i-1][j], dp[i-1][j-iq[i]] + eq[i])
const int MAXN = 15;
int dp[2][2*MAXN+1], iq[401], eq[401], N;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> iq[i] >> eq[i];
    for (int i = 0; i <= 2*MAXN; i++) dp[0][i] = -1e9;
    dp[0][MAXN] = 0;
    int r = 0;
    for (int i = 1; i <= N; i++) {
        int _r = 1 - r;
        for (int j = 0; j <= 2 * MAXN; j++) {
            dp[_r][j] = dp[r][j];
            if (j > iq[i]) dp[_r][j] = max(dp[_r][j], dp[r][j-iq[i]] + eq[i]);
        }
        r = _r;
    }

    int ans = 0;
    for (int j = MAXN; j <= 2 * MAXN; j++) {
        if (dp[r][j] < 0) continue;
        ans = max(ans, dp[r][j] + j - MAXN);
    }
    cout << ans << endl;
}