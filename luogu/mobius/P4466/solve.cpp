//
// Created by 走线大师 on 2021/9/17.
//
#include <bits/stdc++.h>
#define int long long
#define P(k, t, s) (k * k * t * (s + t))
using namespace std;
const int MAX = 1 << 16;
int prime[MAX], visit[MAX], mu[MAX], tot = 0;
void init() {
    memset(visit, 0, sizeof(visit));
    mu[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (visit[i] == 0) prime[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot; j++) {
            if (i * prime[j] >= MAX) break;
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
    init();
    int N, n, Ans = 0;
    cin >> N, n = sqrt(N);
    for (int k = 1; k <= n; k++) {
        int ans = 0;
        for (int t = 2; t <= n / k; t++) {
            int M = N / (k * k * t);
            for (int s = t + 1; s <= min(2 * t - 1, M);) {
                int sj = min(M / (M / s), 2 * t - 1);
                ans += (M / s) * (sj - s + 1);
                s = sj + 1;
            }
        }
        Ans += mu[k] * ans;
    }
    cout << Ans << endl;
}
