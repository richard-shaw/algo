//
// Created by Shaw on 2021/9/23.
//

#include <bits/stdc++.h>

using namespace std;
#define MAXN 10000004
#define int long long
int visit[MAXN], prime[MAXN], mu[MAXN], tot = 0;
void init() {
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

signed main() {
    int T, N;
    cin >> T;
    init();
    while (T--) {
        cin >> N;
        int Ans = 0;
        for (int d = 2; d * d <= N; d++) Ans += mu[d] * (N / d / d);
        cout << N + Ans << endl;
    }
}