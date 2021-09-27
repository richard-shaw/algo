//
// Created by 走线大师 on 2021/9/26.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAXN 5000005
#define MOD 1000000007
int visit[MAXN], prime[MAXN], g[MAXN], tot = 0;
int N, M, K, T;
int ex_pow(int a, int b) {
    int Ans = 1, base = a;
    while (b > 0) {
        if (b & 1) Ans = (Ans * base) % MOD;
        base = (base * base) % MOD;
        b >>= 1;
    }
    return Ans;
}
void init() {
    memset(visit, 0, sizeof(visit));
    g[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i, g[i] = (ex_pow(i, K) - 1) % MOD;
        for (int j = 1; j <= tot && i * prime[j] < MAXN; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                g[i * prime[j]] = (g[i] * ex_pow(prime[j], K)) % MOD;
                break;
            } else {
                g[i * prime[j]] = (g[i] * g[prime[j]]) % MOD;
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        g[i] = (g[i] + g[i-1]) % MOD;
    }
}

signed main() {
    cin >> T >> K;
    init();
    while (T--) {
        cin >> N >> M;
        if (N > M) swap(N, M);
        int Ans = 0;
        for (int i = 1; i <= N;) {
            int j = min(N, min(N / (N / i), M / (M / i)));
            int s = ((N / i) * (M / i)) % MOD;
            Ans = (Ans + (s * (g[j] - g[i - 1])) % MOD) % MOD;
            i = j + 1;
        }
        while (Ans < 0) Ans += MOD;
        cout << Ans << endl;
    }
}