//
// Created by Shaw on 2021/9/20.
//

#include <bits/stdc++.h>
#define MAXN 2003
using namespace std;
int visit[MAXN], prime[MAXN], mu[MAXN], tot = 0;
void init() {
    memset(visit, 0, sizeof(visit));
    mu[1] = 1;
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
}
signed main() {
    init();
    int a, b, s, Ans;
    while(true) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        Ans = 0, s = (2 * a + 1) * (2 * b + 1) - 1;
        for (int d = 1; d <= min(a, b); d++) {
            Ans += mu[d] * (a / d) * (b / d);
        }
        printf("%.7f\n", (double)(4 * Ans + 4) / s);
    }
}