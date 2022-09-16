//
// Created by 走线大师 on 2022/9/10.
//

/**
 * 最长不下降子序列
 * 如果求严格递增，那么for循环中的第一个if为>，且二分时使用lower_bound
 *
 * arr: 原始数列
 * dp:  dp数列，其中dp[i]为以arr[i]结尾的数列最长长度
 * d:   d数列，其中d[i] 表示长度为i时的末尾数字
 */
int arr[maxn], dp[maxn], d[maxn];
int LIS(int n) {
    int len = 0;
    dp[1] = 1, d[len++] = arr[1];

    for (int i = 2; i <= n; i++) {
        if (arr[i] >= d[len-1]) d[len++] = arr[i], dp[i] = len;
        else {
            int idx = upper_bound(d, d + len, arr[i]) - d;
            d[idx] = arr[i], dp[i] = idx + 1;
        }
    }
    int ans = dp[1];
    for (int i = 2; i <= n; i++) ans = max(ans, dp[i]);
    return ans;
}