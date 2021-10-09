//
// Created by Shaw on 2021/10/4.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 4;
int visit[MAXN], prime[MAXN], phi[MAXN], tot = 0, K, N;
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
}
int ex_pow(int a, int b) {
    int base = a, ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        b >>= 1;
    }
    return ans;
}
signed main() {
    init();
    cin >> N >> K;
    int ans = 0;
    for (int T = 1; T <= K; T++) {
        int part = (ex_pow(K / T, N) * phi[T]) % MOD;
        ans = (ans + part) % MOD;
    }
    while (ans < 0) ans += MOD;
    cout << ans << endl;
}