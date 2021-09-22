//
// Created by Shaw on 2021/9/20.
//

#include <bits/stdc++.h>
#define int long long
#define MAXN 50005
#define MOD 1000000007
using namespace std;
int visit[MAXN], prime[MAXN], mu[MAXN], tot = 0;
void init() {
    memset(visit, 0, sizeof(visit));
    mu[0] = 0, mu[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot; j++) {
            if (i * prime[j] >= MAXN) break;
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for (int i = 2; i < MAXN; i++) mu[i] += mu[i-1];
}

int S(int n, int m) {
    int ans = 0;
    if (n <= 0 || m <= 0) return 0;
    if (n > m) return S(m, n);
    for (int d = 1; d <= n; d++) {
        int n0 = n / d, m0 = m / d, s = 0;
        for (int k = 1; k <= n0;) {
            int j = min(min(n0 / (n0 / k), m0 / (m0 / k)), n0);
            s = (s + ((mu[j] - mu[k-1]) * (n0 / k) * (m0 / k)) % MOD) % MOD;
            k = j + 1;
        }
        ans = (ans + (d * s) % MOD) % MOD;
    }
    return ans;
}

int Q(int i1, int j1, int i2, int j2) {
    int r = (S(i1 - 1, j1 - 1) + S(i2, j2) - S(i1 - 1, j2) - S(i2, j1 - 1)) % MOD;
    while (r < 0) r += MOD;
    return r;
}

signed main() {
    init();
    int T, n, m, i1, i2, j1, j2;
    cin >> T >> n >> m;
    while(T--) {
        cin >> i1 >> j1 >> i2 >> j2;
        cout << Q(i1, j1, i2, j2) << endl;
    }
}