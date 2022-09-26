//
// Created by 走线大师 on 2022/9/27.
//

const int maxn = 3e6 + 9;
long long dp[maxn];
void init(int n, long long mod) {
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[mod % i] * (mod - (mod / i))) % mod;
    }
}
