//
// Created by Shaw on 2021/10/6.
//
//#pragma GCC optimize("Ofast", "inline", "-ffast-math")
//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const double eps = 1e-14;
const int MAXN = 1e7 + 6;
int visit[MAXN], mu[MAXN], prime[MAXN], f[MAXN], tot = 0;
double _div[MAXN];
void init() {
    memset(visit, 0, sizeof(visit));
    memset(f, 0, sizeof(f));
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
    for (int i = 1; i <= tot; i++) {
        int p = prime[i];
        for (int k = 1; k * p < MAXN; k++) {
            f[k * p] += mu[k];
        }
    }
    for (int i = 1; i < MAXN; i++) f[i] += f[i-1];
    for (int i = 1; i < MAXN; i++) _div[i] = 1.0 / i + eps;
}
signed main() {
//    clock_t t1 = clock();
    init();
    int T, N, M;
    cin >> T;
    while (T--) {
        int Ans = 0;
        cin >> N >> M;
        if (N > M) swap(N, M);
        for (int t = 1; t <= N; ) {
            int nt = N * _div[t], mt = M * _div[t];
            int nnt = N * _div[nt], mmt = M * _div[mt];
            int t0 = min(N, min(nnt, mmt));
            Ans += nt * mt * (f[t0] - f[t-1]);
            t = t0 + 1;
        }
        cout << Ans << endl;
    }
//    clock_t t2 = clock();
//    cout << ((double)(t2-t1)/CLOCKS_PER_SEC) << endl;
}