//
// Created by 走线大师 on 2021/9/7.
//


#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e4 + 21;
int visit[maxn], prime[maxn], mu[maxn], d[maxn], num[maxn], tot = 0;
void init() {
    memset(visit, 0, sizeof(visit));
    mu[0] = 0, d[0] = 0;
    mu[1] = 1, d[1] = 1, num[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (visit[i] == 0) prime[++tot] = i, mu[i] = -1, d[i] = 2, num[i] = 1;
        for (int j = 1; j <= tot; j++) {
            if (prime[j] * i >= maxn) break;
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                num[i * prime[j]] = num[i] + 1;
                d[i * prime[j]] = d[i] / num[i * prime[j]] * (num[i * prime[j]] + 1);
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
                num[i * prime[j]] = 1;
                d[i * prime[j]] = d[i] * 2;
            }
        }
    }
    for (int i = 1; i < maxn; i++) {
        mu[i] += mu[i-1];
        d[i] += d[i-1];
    }
}


void solve(int n, int m) {
    int Ans = 0;
    for (int i = 1; i <= min(n, m);) {
        int j1 = n / (n / i), j2 = m / (m / i);
        int j = min(j1, j2);
        Ans += (mu[j] - mu[i-1]) * d[n / i] * d[m / i];
        i = j + 1;
    }
    cout << Ans << endl;
}

signed main() {
    init();
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        solve(n, m);
    }
}