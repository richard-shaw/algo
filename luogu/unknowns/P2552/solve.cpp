//
// Created by 走线大师 on 2021/9/5.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 5e4 + 3;
int v[N], prime[N], mu[N], tot = 0, mu_sum[N];

void init() {
    memset(v, 0, sizeof(v));
    mu[1] = 1, mu_sum[0] = 0;
    for (int i = 2; i < N; i++) {
        if (!v[i]) mu[i] = -1, prime[++tot] = i;
        for (int j = 1; j <= tot; j++) {
            if (prime[j] * i >= N) break;
            v[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for (int i = 1; i < N; i++) mu_sum[i] = mu_sum[i-1] + mu[i];
}

int Q(int p, int q) {
    if (p < 1 || q < 1) return 0;
    int res = 0;
    for (int i = 1; i <= min(p, q);) {
        int j = min(p / (p / i), q / (q / i));
        res += (mu_sum[j] - mu_sum[i-1]) * (p / i) * (q / i);
        i = j + 1;
    }
    return res;
}

signed main() {
    init();
    int t, a, b, c, d, k;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d >> k;
        a = (a - 1) / k, b = b / k, c = (c - 1) / k, d = d / k;
        cout << (Q(b, d) + Q(a, c) - Q(a, d) - Q(b, c)) << endl;
    }
}