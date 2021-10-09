//
// Created by Shaw on 2021/10/5.
//

#include <bits/stdc++.h>

using namespace std;
#define int signed long long
const int MAXN = 1e6 + 4;
int visit[MAXN], prime[MAXN], phi[MAXN], tot = 0;
void init() {
    memset(visit, 0, sizeof(visit));
    phi[0] = 0, phi[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i, phi[i] = i - 1;
        for (int j = 1; j <= tot && i * prime[j] < MAXN; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
    for (int i = 2; i < MAXN; i++) phi[i] += phi[i-1];
}
signed main() {
    int N;
    init();
    while (true) {
        cin >> N;
        if (N == 0) break;
        int ans = 0;
        for (int t = 1; t <= N; ) {
            int nt = N / t, t0 = N / nt;
            ans += (phi[t0] - phi[t-1]) * nt * nt;
            t = t0 + 1;
        }
        ans -= (N * (N + 1) / 2);
        cout << (ans >> 1) << endl;
    }
}