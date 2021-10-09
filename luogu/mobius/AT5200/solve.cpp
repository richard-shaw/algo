//
// Created by Shaw on 2021/10/6.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
#define MAXN 1000020
int A[MAXN / 5], C[MAXN], N, visit[MAXN], mu[MAXN], prime[MAXN], tot = 0, f[MAXN], M = -1;
void init() {
    memset(C, 0, sizeof(C));
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
void initF() {
    memset(f, 0, sizeof(f));
    for (int t = 1; t <= M; t++) {
        for (int k = 1; k * t <= M; k++) {
            int i = k * t;
            f[t] = (f[t] + i * C[i]) % MOD;
        }
    }
}
int ex_pow(int a, int b) {
    int ans = 1, base = a;
    while (b > 0) {
        if (b & 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        b >>= 1;
    }
    return ans;
}
signed main() {
    init();
    int rs = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        C[A[i]]++;
        rs = (rs + A[i]) % MOD;
        if (M < A[i]) M = A[i];
    }
    initF();
    int Ans = 0;
    for (int d = 1; d < M; d++) {
        for (int k = 1; k < M / d; k++) {
            int f2 = f[d * k] * f[d * k];
            Ans = (Ans + f2 * mu[k] / d) % MOD;
        }
    }
    Ans -= rs;
    while (Ans < 0) Ans += MOD;
    Ans = (Ans * ex_pow(2, MOD - 2)) % MOD;
    cout << Ans << endl;
}