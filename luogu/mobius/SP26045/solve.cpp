// Created by Shaw on 2021/9/20.

#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAXN 1000004
#define MOD 1000000007
#define EPS 0.000000000000001
#define _div(n, i) (int)(n * dv[i])
int visit[MAXN], prime[MAXN], phi[MAXN], tot = 0;
double dv[MAXN];
void init() {
    memset(visit, 0, sizeof(visit));
    phi[1] = 1;

    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i, phi[i] = i - 1;
        for (int j = 1; j <= tot && i * prime[j] < MAXN; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = (phi[i] * prime[j]) % MOD;
                break;
            } else {
                phi[i * prime[j]] = (phi[i] * phi[prime[j]]) % MOD;
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        phi[i] = (phi[i] + phi[i - 1]) % MOD;
    }
    for (int i = 1; i < MAXN; i++) {
        dv[i] = 1. / i * (1 + EPS);
    }
}

int S(int N, int M) {
    int Ans = 0;
    if (N > M) swap(N, M);
    for (int i = 1; i <= N; ) {
        int n0 = _div(N, i), m0 = _div(M, i);//N / i, m0 = M / i;
        int j = min(N, min(_div(N, n0), _div(M, m0)));
        int Q = (n0 * m0) % MOD;
        Ans = (Ans + (Q * (phi[j] - phi[i - 1])) % MOD) % MOD;
        i = j + 1;
    }
    while (Ans < 0) Ans += MOD;
    return Ans;
}

void solve() {
    int T, N, M, i1, i2, j1, j2;
    cin >> T >> N >> M;
//    N = M = 1e6;
//    T = 5e4;
    while (T--) {
        cin >> i1 >> j1 >> i2 >> j2;
//        i1 = j1 = i2 = j2 = 1e6;
        if (i1 > i2 || j1 > j2) {
            cout << 0 << endl;
            continue;
        }
        int Ans = (S(i1 - 1, j1 - 1) + S(i2, j2) - S(i1 - 1, j2) - S(i2, j1 - 1)) % MOD;
        while (Ans < 0) Ans += MOD;
        cout << Ans << endl;
    }
}

signed main() {
    init();
//    clock_t t1 = clock();
    solve();
//    clock_t t2 = clock();
//    cout << (double) (t2 - t1) / CLOCKS_PER_SEC << endl;
}
