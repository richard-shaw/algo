//
// Created by Shaw on 2021/10/4.
//
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MOD 1000000007
#define MAXN 1000003
#define eps 0.00000000000001
#define INF 0x7fffffffffffffff
int visit[MAXN], prime[MAXN], phi[MAXN], tot = 0;
double _dv[MAXN];
void init() {
    memset(visit, 0, sizeof(visit));
    phi[0] = 0, phi[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i, phi[i] = i - 1;
        for (int j = 1; j <= tot && i * prime[j] < MAXN; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
    for (int i = 2; i < MAXN; i++) phi[i] = (phi[i] + phi[i - 1]) % MOD;
    for (int i = 1; i < MAXN; i++) _dv[i] = 1.0 / i + eps;
}
inline int min(int a, int b) { return a < b ? a : b; }
inline int _div(int n, int t) { return t == 0 ? INF : (n < t ? 0 : (int)(n * _dv[t])); }
int S(int n, int m) {
    if (n > m) swap(n, m);
    int ans = 0, min_nm = min(n, m);
    for (int t = 1; t <= min_nm; ) {
        int nt = _div(n, t), mt = _div(m, t);
        int t0 = min(min_nm, min(_div(n, nt), _div(m, mt)));
        int pt = (nt * mt) % MOD;
        ans = (ans + (pt * (phi[t0] - phi[t-1])) % MOD) % MOD;
        t = t0 + 1;
    }
    if (ans < 0) ans += MOD;
    return ans;
}
signed main() {
    init();
    int T, N, M, i1, i2, j1, j2;
    cin >> T >> N >> M;
//    T = 50000, N = M = 1e6;
//    clock_t t1 = clock();
    while (T--) {
        cin >> i1 >> j1 >> i2 >> j2;
//        i1 = j1 = 1, i2 = j2 = 1e6;
        int Ans = (S(i2, j2) + S(i1-1, j1-1) - S(i1-1, j2) - S(i2, j1-1)) % MOD;
        if (Ans < 0) Ans += MOD;
        cout << Ans << endl;
    }
//    clock_t t2 = clock();
//    cout << ((double)(t2 - t1) / CLOCKS_PER_SEC) << endl;
};