//
// Created by Shaw on 2021/10/7.
//
//#pragma GCC optimize("Ofast", "inline", "-ffast-math")
//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
using namespace std;
#define _int int
#define int long long
#define INF 0x7ffffffffffffff
#define MOD 998244353
#define MAXN 10000004
char visit[MAXN], mu[MAXN];
_int prime[MAXN / 10];
int idk[MAXN], tot = 0, N, K, cg[MAXN / 2], _D[MAXN / 2], S[MAXN / 2];
int ex_pow(int a, int b) {
    int base = a, ans = 1;
    while (b > 0) {
        if (b & 1) ans *= base;
        base *= base;
        b >>= 1;
        if (ans >= MOD) ans %= MOD;
        if (base >= MOD) base %= MOD;
    }
    return ans;
}
void init() {
    for (int i = 0; i < MAXN / 2; i++) _D[i] = -INF;
    memset(visit, 0, sizeof(visit));
    mu[1] = idk[1] = 1, cg[0] = 0, S[0] = 0;
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i, mu[i] = -1, idk[i] = ex_pow(i, K);
        for (int j = 1; j <= tot && i * prime[j] < MAXN; j++) {
            visit[i * prime[j]] = 1;
            idk[i * prime[j]] = idk[i] * idk[prime[j]];
            if (idk[i * prime[j]] >= MOD) idk[i * prime[j]] %= MOD;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for (int i = 1; i < MAXN / 2; i++) {
        cg[i] = cg[i-1] + i * idk[i] * mu[i] * mu[i];
        if (cg[i] >= MOD) cg[i] %= MOD;
    }
    for (int i = 1; i < MAXN; i++) {
        idk[i] += idk[i-1];
        if (idk[i] >= MOD) idk[i] %= MOD;
    }
    for (int i = 1; i < MAXN / 2; i++) {
        S[i] = (S[i-1] + 2 * (idk[2 * i] - idk[i]) - idk[2 * i] + idk[2 * i - 1]) % MOD;
        if (S[i] < 0) S[i] += MOD;
    }
}
int D(int n) {
    if (n == 0) return 0;
    if (_D[n] != -INF) return _D[n];
    int Ans = cg[n];
    for (int i = 2; i <= n;) {
        int j = min(n, n / (n / i));
        Ans = (Ans - D(n / i) * (idk[j] - idk[i-1])) % MOD;
        i = j + 1;
        while (Ans < 0) Ans += MOD;
    }
    return _D[n] = Ans;
}
void memory() {
    double M = 1024.0 * 1024.0;
    double s1 = sizeof(visit) / M;
    double s2 = sizeof(idk) / M;
    double s3 = sizeof(mu) / M;
    double s4 = sizeof(prime) / M;
    double s5 = sizeof(cg) / M;
    double s6 = sizeof(_D) / M;
    double s8 = sizeof(S) / M;
    cout << (s1+s2+s3+s4+s5+s6+s8) << endl;
}
signed main() {
//    memory();
//    clock_t t1 = clock();
    cin >> N >> K;
//    N = 5e6, K = 1e18;
    init();
    int Ans = 0;
    for (int T = 1; T <= N; ) {
        int t0 = N / (N / T);
        Ans = (Ans + S[N / T] * (D(t0) - D(T - 1))) % MOD;
        T = t0 + 1;
    }
    while (Ans < 0) Ans += MOD;
    cout << Ans << endl;
//    clock_t t2 = clock();
//    cout << ((double)(t2 - t1) / CLOCKS_PER_SEC) << endl;
}