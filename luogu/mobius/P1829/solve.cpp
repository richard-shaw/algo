//
// Created by Shaw on 2021/9/20.
//

#include <bits/stdc++.h>
#define int long long
#define MAXN 10000005
#define MOD 20101009
using namespace std;
int visit[MAXN], prime[MAXN], mu[MAXN], tot = 0;

int mul(int cnt, ...) {
    int Ans = 1;
    va_list va;
    va_start(va, cnt);
    for (int i = 1; i <= cnt; i++) {
        Ans = (Ans * va_arg(va, long long)) % MOD;
    }
    va_end(va);
    return Ans;
}
void init() {
    memset(visit, 0, sizeof(visit));
    mu[0] = 0, mu[1] = 1;
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
    for (int i = 2; i < MAXN; i++) {
        mu[i] = (mu[i-1] + mul(3, mu[i], i, i)) % MOD;
    }
}
int G(int N) {
    return (N * (N + 1) / 2) % MOD;
}
int Sum(int n, int m) {
    int Ans = 0;
    for (int d = 1; d <= n;) {
        int j = min(n / (n / d), m / (m / d));
        Ans = (Ans + mul(3, mu[j] - mu[d-1], G(n / d), G(m / d))) % MOD;
        d = j + 1;
    }
    return Ans;
}

signed main() {
    init();
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    int Ans = 0;
    for (int d = 1; d <= n;) {
        int j = min(n / (n / d), m / (m / d));
        Ans = (Ans + mul(2, Sum(n / d, m / d), G(j) - G(d-1))) % MOD;
        d = j + 1;
    }
    while (Ans < 0) Ans += MOD;
    cout << Ans << endl;
}