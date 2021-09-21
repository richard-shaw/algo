//
// Created by 走线大师 on 2021/9/17.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAX = 2e6 + 5;
int visit[MAX], prime[MAX], tao[MAX], tot = 0, N, M, P;

int D(int n, int p) {
    int Ans = 0;
    while(n % p == 0) {
        Ans++;
        n /= p;
    }
    return Ans;
}

void init() {
    memset(visit, 0, sizeof(visit));
    tao[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (visit[i] == 0) prime[++tot] = i, tao[i] = 2;
        for (int j = 1; j <= tot; j++) {
            if (i * prime[j] >= MAX) break;
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                int d0 = D(i, prime[j]);
                tao[i * prime[j]] = tao[i] / (d0 + 1) * (d0 + 2);
                break;
            } else {
                tao[i * prime[j]] = tao[i] * tao[prime[j]];
            }
        }
    }
}

int S(int n, int d) {
    int Ans = 0;
    for (int i = d; i <= n; i += d) {
        Ans = (Ans + tao[i]) % P;
    }
    return Ans;
}

signed main() {
    init();
    cin >> N >> M >> P;
    int Ans = 0;
    for (int d = 1; d <= min(N, M); d++) {
        Ans = (Ans + S(N, d) * S(M, d)) % P;
    }
    cout << Ans << endl;
}