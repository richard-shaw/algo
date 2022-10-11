//
// Created by 走线大师 on 2022/6/29.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int pow2[61], dp[61][60];
int N, M;
signed main() {
    pow2[0] = 1ll;
    for (int i = 1; i <= 60; i++) pow2[i] = pow2[i-1] << 1;
    cin >> N >> M;
    if (N > 60) cout << 0 << endl;
    else {
        for (int i = 0; i <= 60; i++) for (int j = 0; j < 60; j++) dp[i][j] = 0;
        for (int t = 0; t < 60; t++) dp[1][t] = max(0ll, min(M, pow2[t+1]-1)-pow2[t]+1);
        for (int n = 2; n <= N; n++) {
            for (int t = 0; t < 60; t++) {
                int ans = 0ll;
                for (int k = 0; k < t; k++) {
                    int x = max(0ll, min(M, pow2[t+1]-1)-pow2[t]+1) % mod;
                    ans = (ans + (dp[n-1][k] * x) % mod) % mod;
                }
                while (ans < 0) ans += mod;
                dp[n][t] = ans;
            }
        }
        int Ans = 0;
        for (int k = 0; k < 60; k++) Ans = (Ans + dp[N][k]) % mod;
        while (Ans < 0) Ans += mod;
        cout << Ans << endl;
    }
}

