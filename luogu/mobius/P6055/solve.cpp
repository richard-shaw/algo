//
// Created by Shaw on 2021/10/4.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 998244353;
const int MAXN = 1e6+3;
int visit[MAXN], prime[MAXN], mu[MAXN], tot = 0, N;
map<int, int> mu_map;
void init() {
    mu_map.clear();
    memset(visit, 0, sizeof(MAXN));
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
    for (int i = 2; i < MAXN; i++) mu[i] = (mu[i] + mu[i - 1]) % MOD;
}
int S(int n) {
    if (n < MAXN) return mu[n];
    if (mu_map.find(n) != mu_map.end()) return mu_map[n];
    int result = 1;
    for (int i = 2; i <= n; ) {
        int j = n / (n / i);
        result = (result - S(n / i) * (j - i + 1)) % MOD;
        if (result < 0) result += MOD;
        i = j + 1;
    }
    return mu_map[n] = result;
}
signed main() {
    cin >> N;
    init();
    int res = 0;
    for (int d = 1; d <= N;) {
        int d0 = N / (N / d);
        int ND = N / d, ND3 = (((ND * ND) % MOD) * ND) % MOD;
        res = (res + (ND3 * (S(d0) - S(d-1))) % MOD) % MOD;
        d = d0 + 1;
    }
    while (res < 0) res += MOD;
    cout << res << endl;
}