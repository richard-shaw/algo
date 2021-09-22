//
// Created by Shaw on 2021/9/21.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAXN 1500003
int visit[MAXN], prime[MAXN], mu[MAXN], tot = 0;
void init() {
    memset(visit, 0, sizeof(visit));
    mu[1] = 1;
    for (int i = 2; i < MAXN; i++ ) {
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
int ex_pow(int a, int b, int p) {
    int ans = 1, base = a;
    while (b > 0) {
        if (b & 1) ans = (ans * base) % p;
        base = (base * base) % p;
        b >>= 1;
    }
    return ans;
}
int S(int a, int q, int n, int p) {
    if (n == 1) return a % p;
    int S1 = S(a, q, n / 2, p);
    int Ans = (((1 + ex_pow(q, n / 2, p)) % p) * S1) % p;
    if (n & 1) Ans = (Ans + (a * ex_pow(q, n - 1, p)) % p) % p;
    return Ans;
}
signed main() {
    init();
    int T, N, P;
    cin >> T;
    while(T--) {
        cin >> N >> P;
        int Ans = 0;
        for (int d = 1; d <= N; d++) {
            int dd = ex_pow(d, d, P), ddk = 1;
            for (int k = 1; k <= N / d; k++) {
                ddk = (ddk * dd) % P;
                int Sq = S(ddk, ddk, N / d / k, P);
                Ans = (Ans + mu[k] * Sq * Sq) % P;
            }
        }
        while(Ans < 0) Ans += P;
        cout << Ans << endl;
    }
}