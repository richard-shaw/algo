//
// Created by 走线大师 on 2021/10/8.
//
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int MAXN = 1e7 + 9;
int visit[MAXN], prime[MAXN], mu[MAXN], tot = 0, Sum[MAXN];
void init() {
    memset(Sum, 0, sizeof(Sum));
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
    for (int i = 1; i <= tot; i++) {
        for (int k = 1; k * prime[i] < MAXN; k++) {
            Sum[k * prime[i]] += mu[k];
        }
    }
    for (int i = 1; i <= MAXN; i++) Sum[i] += Sum[i-1];
}

signed main() {
//    clock_t t1 = clock();
    init();
    int T;
    cin >> T;
//    T = 10;
    while (T--) {
        int N, M, Ans = 0;
        cin >> N >> M;
//        N = M = 1e7;
        if (N > M) swap(N, M);
        for (int t = 1; t <= N;) {
            int t0 = min(N, min(N / (N / t), M / (M / t)));
            Ans += (N / t) * (M / t) * (Sum[t0] - Sum[t-1]);
            t = t0 + 1;
        }
        cout << Ans << endl;
    }
//    clock_t t2 = clock();
//    cout << ((double)(t2 - t1) / CLOCKS_PER_SEC) << endl;
}
