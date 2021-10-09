//
// Created by 走线大师 on 2021/10/8.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF 0x7fffffffffffffff
const int MAXN = 1e6 + 6;
const int MOD = 19260817;
int visit[MAXN], prime[MAXN], mu[MAXN], tot = 0, S[MAXN];
void init() {
    memset(visit, 0, sizeof(visit));
    mu[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot && i * prime[j] < MAXN; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for (int i = 0; i < MAXN; i++) S[i] = -INF;
}

int Sum(int n) {
    if (n == 0) return 0;
    if (S[n] != -INF) return S[n];
    int ans = (n * n) % MOD;
    for (int i = 2; i <= n;) {
        int j = min(n, n / (n / i));
        ans = (ans - Sum(n / i) * (j - i + 1)) % MOD;
        i = j + 1;
    }
    while (ans < 0) ans += MOD;
    return S[n] = ans;
}

int ex_pow(int a, int b) {
    int base = a, ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        b >>= 1;
    }
    return ans;
}

signed main() {
    init();
    int T, N, Ans;
    cin >> T;
    while (T--) {
        Ans = 0; cin >> N;
        for (int t = 1; t <= N;) {
            int t0 = min(N, N / (N / t));
            int q = (N / t); q = (q * q) % MOD;
            Ans = (Ans + q * (Sum(t0) - Sum(t - 1))) % MOD;
            t = t0 + 1;
        }
        while (Ans < 0) Ans += MOD;
        Ans = (36 * Ans) % MOD;
        int N1 = (((N * (N + 1)) % MOD) * (2 * N + 1)) % MOD;
        N1 = (N1 * N1) % MOD;
        Ans = (N1 * ex_pow(Ans, MOD - 2)) % MOD;
        cout << Ans << endl;
    }
}