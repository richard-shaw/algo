
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e6 + 3;
int mu[maxn], visit[maxn], prime[maxn];

void get_mu() {
    memset(visit, 0, sizeof(visit));
    int tot = 0;
    mu[0] = 0, mu[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!visit[i]) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot; j++) {
            if (i * prime[j] >= maxn) break;
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for (int i = 2; i < maxn; i++) mu[i] += mu[i-1];
}

int F(int N) {
    int Ans = 0;
    for (int d = 1; d <= N;) {
        int P = N / d, D = N / P;
        Ans += (mu[D] - mu[d-1]) * P * P;
        d = D + 1;
    }
    return Ans;
}

signed main() {
    get_mu();
    int N, Ans = 0;
    cin >> N;
    for (int d = 1; d <= N; d++) {
        Ans += d * F(N / d);
    }
    Ans = (Ans - N * (N + 1) / 2) >> 1;
    cout << Ans << endl;
}