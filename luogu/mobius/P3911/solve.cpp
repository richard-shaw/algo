//
// Created by 走线大师 on 2021/9/18.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAX = 5e4 + 5;
int visit[MAX], mu[MAX], prime[MAX], S[MAX], tot = 0, A[MAX], C[MAX], n, N = -1, Ans = 0;
void init() {
    memset(visit, 0, sizeof(visit));
    memset(S, 0, sizeof(S));
    memset(C, 0, sizeof(C));
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
    for (int d = 1; d < MAX; d++) {
        for (int k = 1; ; k++) {
            int T = k * d;
            if (T >= MAX) break;
            S[T] += d * mu[d];
        }
    }
}

signed main() {
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        N = max(N, A[i]);
        C[A[i]]++;
    }
    for (int T = 1; T <= N; T++) {
        int IC = 0;
        for (int i = 1; i <= N / T; i++) {
            IC += i * C[i * T];
        }
        Ans += T * IC * IC * S[T];
    }
    cout << Ans << endl;
}