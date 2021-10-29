//
// Created by 走线大师 on 2021/10/10.
//
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1003;
int dp[2][MAXN];

int main() {
//    clock_t t1 = clock();
    for (int i = 0; i < MAXN; i++) dp[0][i] = 0;
    int M, S, T, t = 1000000;
    cin >> M >> S >> T;
//    M = 1000, S = 100000000, T = 300000;
    int row = 0;
    for (int i = 0; i < MAXN; i++) dp[row][i] = 0;
    for (int i = 1; i <= T; i++) {
        int _r = (row + 1) % 2;
        for (int q = 0; q <= M; q++) {
            int ans = max(dp[row][q] + 17, dp[row][min(q + 4, M)]);
            if (q >= 10) ans = max(ans, dp[row][q - 10] + 60);
            dp[_r][q] = ans;
            if (ans >= S) t = min(t, i);
        }
        row = _r;
    }
    int ans = 0;
    for (int q = 0; q <= M; q++) ans = max(ans, dp[row][q]);
    if (ans >= S) cout << "Yes\n" << t << endl;
    else cout << "No\n" << ans << endl;
//    clock_t t2 = clock();
//    cout << ((double) (t2 - t1) / CLOCKS_PER_SEC) << endl;
}