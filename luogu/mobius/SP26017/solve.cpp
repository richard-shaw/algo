//
// Created by Shaw on 2021/9/20.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 50004
#define MOD 1000000007

int visit[MAXN], prime[MAXN], phi[MAXN], tot = 0;
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
}

int S(int N, int M) {
    int Ans = 0;
    if (N > M) swap(N, M);
    for (int i = 1; i <= N; ) {
        int j = min(N, min(N / (N / i), M / (M / i)));
        int Q = ((N / i) * (M / i)) % MOD;
        Ans = (Ans + (Q * (phi[j] - phi[i - 1])) % MOD) % MOD;
        i = j + 1;
    }
    while (Ans < 0) Ans += MOD;
    return Ans;
}

signed main() {
    init();
    int T, N, M, i1, i2, j1, j2;
    cin >> T >> N >> M;
    while (T--) {
        cin >> i1 >> j1 >> i2 >> j2;
        if (i1 > i2 || j1 > j2) {
            cout << 0 << endl;
            continue;
        }
        int Ans = (S(i1 - 1, j1 - 1) + S(i2, j2) - S(i1 - 1, j2) - S(i2, j1 - 1)) % MOD;
        while (Ans < 0) Ans += MOD;
        cout << Ans << endl;
    }
}