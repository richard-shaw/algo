//
// Created by Shaw on 2021/9/17.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 4e4 + 4;
int visit[maxn], mu[maxn], prime[maxn], tot = 0;
void init() {
    memset(visit, 0, sizeof(visit));
    mu[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (visit[i] == 0) prime[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot; j++) {
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
}

int solve(int N) {
    int Ans = 0;
    for (int d = 1; d <= N; d++) {
        Ans += mu[d] * (N / d) * (N / d);
    }
    return Ans;
}

signed main() {
    init();
    int N;
    cin >> N;
    if (N == 1) cout << 0 << endl;
    else cout << 2 + solve(N-1) << endl;
}