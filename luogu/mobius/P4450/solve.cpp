//
// Created by 走线大师 on 2021/9/17.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAX = 1e6 + 54;
int visit[MAX], prime[MAX], mu[MAX], tot = 0;

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
    int A, B, D;
    cin >> A >> B >> D;
    A /= D, B /= D;
    if (A > B) swap(A, B);
    int Ans = 0;
    for (int d = 1; d <= A; d++) {
        Ans += mu[d] * (A / d) * (B / d);
    }
    cout << Ans << endl;
}