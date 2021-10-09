//
// Created by 走线大师 on 2021/10/8.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e5 + 9;
int visit[MAXN], prime[MAXN], phi[MAXN], tot = 0;
void init() {
    memset(visit, 0, sizeof(visit));
    phi[0] = 0, phi[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i, phi[i] = i - 1;
        for (int j = 1; j <= tot && i * prime[j] < MAXN; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
    for (int i = 2; i < MAXN; i++) phi[i] += phi[i - 1];
}

signed main() {
    init();
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    int Ans = 0;
    for (int T = 1; T <= n;) {
        int t0 = min(n, min(n / (n / T), m / (m / T)));
        Ans += (n / T) * (m / T) * (phi[t0] - phi[T - 1]),
        T = t0 + 1;
    }
    cout << (2 * Ans - n * m) << endl;
}