//
// Created by 走线大师 on 2021/9/27.
//
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MOD 1000000007
#define MAXN 100004
int visit[MAXN], prime[MAXN], mu[MAXN], tot = 0;
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
}
int ex_pow(int a, int b) {
    int Ans = 1, base = a;
    while (b > 0) {
        if (b & 1) Ans = (Ans * base) % MOD;
        base = (base * base) % MOD;
        b >>= 1;
    }
    return Ans;
}
int cov(int P, int Q) {
    Q = ex_pow(Q, MOD - 2);
    return (P * Q) % MOD;
}


signed main() {
    init();
    int M, Ans = 1;
    cin >> M;
    for (int d = 2; d <= M; d++) {
        int s = cov(M / d, M - M / d);
        Ans = (Ans - mu[d] * s) % MOD;
    }
    while (Ans < 0) Ans += MOD;
    cout << Ans << endl;
}
