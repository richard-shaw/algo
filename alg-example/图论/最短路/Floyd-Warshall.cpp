//
// Created by 走线大师 on 2022/9/9.
//

/**
 * 任意节点对最短路
 * 任意图
 * 能检测负环
 * 小图
 * 时间复杂度O(N^3)
 */

const int maxn = 300;
int dp[maxn][maxn];

void solve(int n) {
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
            }
}