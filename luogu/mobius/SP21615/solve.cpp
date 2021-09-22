//
// Created by Shaw on 2021/9/20.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100003
int visit[MAX], prime[MAX], phi[MAX], tot = 0;

void init() {
    memset(visit, 0, sizeof(visit));
    phi[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (visit[i] == 0) prime[++tot] = i, phi[i] = i - 1;
        for (int j = 1; j <= tot; j++) {
            if (i * prime[j] >= MAX) break;
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
    for (int i = 2; i < MAX; i++) phi[i] += phi[i-1];
}

void solve() {
    int N;
    cin >> N;
    cout << (N * (N + 1) / 2 - phi[N]) << endl;
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}