//
// Created by Shaw on 2021/10/13.
//

#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
const int MAXN = 10030;
// dp[n][m] 到达(n, m)的最小点击数
int N, M, K, x[MAXN], y[MAXN], dp[MAXN][MAXN / 10], L[MAXN], H[MAXN], P[MAXN];
int main() {
    for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN / 10; j++) dp[i][j] = INF;
    memset(P, 0, sizeof(P));
    cin >> N >> M >> K;
    for (int i = 0; i <= N; i++) dp[i][0] = INF;
    for (int j = 1; j <= M; j++) dp[0][j] = 0;
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    for (int j = 1; j <= K; j++) {
        int p, l, h;
        cin >> p >> l >> h;
        P[p] = 1, L[p] = l, H[p] = h;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) if (j > x[i-1]) dp[i][j] = min(dp[i][j], min(dp[i-1][j-x[i-1]], dp[i][j-x[i-1]]) + 1);
        for (int j = 1; j <= M; j++) if (j + y[i-1] <= M) dp[i][j] = min(dp[i][j], dp[i-1][j+y[i-1]]);
        for (int k = 0; k < x[i-1]; k++) dp[i][M] = min(dp[i][M], min(dp[i-1][M-k], dp[i][M-k]) + 1);
        if (P[i] == 1) for (int j = 1; j <= M; j++) if (j <= L[i] || j >= H[i]) dp[i][j] = INF;
    }

    int stopped = 0;
    for (int i = 1; i <= N; i++) {
        bool ok = false;
        for (int j = 1; j <= M; j++) {
            if (dp[i][j] < INF) { ok = true; break; }
        }
        if (!ok) break;
        stopped ++;
    }
    if (stopped == N) {
        int ans = INF;
        for (int j = 1; j <= M; j++) ans = min(ans, dp[N][j]);
        cout << "1\n" << ans << endl;
    } else {
        int ans = 0;
        for (int i = 1; i <= stopped; i++) ans += P[i];
        cout << "0\n" << ans << endl;
    }

}