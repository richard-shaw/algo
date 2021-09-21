//
// Created by 走线大师 on 2021/9/7.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 5e4 + 43;
int v[maxn], prime[maxn], mu[maxn], tot = 0;

void init() {
    memset(v, 0, sizeof(v));
    mu[1] = 1, mu[0] = 0;
    for (int i = 2; i < maxn; i++) {
        if (v[i] == 0) prime[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot; j++) {
            if (prime[j] * i >= maxn) break;
            v[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for (int i = 2; i < maxn; i++) {
        mu[i] += mu[i-1];
    }
}

int solve(int a, int b) {
    int Ans = 0;
    for (int i = 1; i <= min(a, b);) {
        int j = min(a / (a / i), b / (b / i));
        Ans += (mu[j] - mu[i - 1]) * (a / i) * (b / i);
        i = j + 1;
    }
    return Ans;
}

signed main() {
    init();
    int t, a, b, d;
    cin >> t;
    while(t--) {
        cin >> a >> b >> d;
        a /= d, b /= d;
        cout << solve(a, b) << endl;
    }
}