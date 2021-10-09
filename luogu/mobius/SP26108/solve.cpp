//
// Created by Shaw on 2021/10/4.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAXN 1000004
#define MOD 1000000007
int visit[MAXN], prime[MAXN], K[MAXN], tot = 0;
int mul(int c, ...) {
    va_list va;
    va_start(va, c);
    int ans = 1;
    for (int i = 1; i <= c; i++) {
        int arg = va_arg(va, long long);
        ans = (ans * arg) % MOD;
    }
    va_end(va);
    return ans;
}
void init() {
    memset(visit, 0, sizeof(visit));
    K[0] = 0, K[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i, K[i] = i - 1;
        for (int j = 1; j <= tot && i * prime[j] < MAXN; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                if (i % (prime[j] * prime[j]) == 0) K[i * prime[j]] = 0;
                else K[i * prime[j]] = (K[i / prime[j]] * (-prime[j])) % MOD;
                break;
            } else {
                K[i * prime[j]] = (K[i] * K[prime[j]]) % MOD;
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        K[i] = (mul(3, K[i], i, i) + K[i - 1]) % MOD;
    }
}
int S(int x) {
    return (x * (x + 1) / 2) % MOD;
}
signed main() {
    init();
    int t; cin >> t; while (t--) {
        int n, m, ans = 0;
        cin >> n >> m;
        if (n > m) swap(n, m);
        for (int T = 1; T <= n; ) {
            int T0 = min(n, min(n / (n / T), m / (m / T))), SK = (K[T0] - K[T - 1]) % MOD;
            ans = (ans + mul(3, SK, S(n / T), S(m / T))) % MOD;
            T = T0 + 1;
        }
        while (ans < 0) ans += MOD;
        cout << ans << endl;
    }
}