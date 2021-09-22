//
// Created by Shaw on 2021/9/18.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAXN = 1e6 + 5;
int visit[MAXN], prime[MAXN], phi[MAXN], tot = 0, Ans[MAXN];
int S(int d) {
    return d == 1 ? 1 : d * phi[d] / 2;
}
void init() {
    memset(visit, 0, sizeof(visit));
    memset(Ans, 0, sizeof(Ans));
    phi[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i, phi[i] = i - 1;
        for (int j = 1; j <= tot; j++) {
            if (i * prime[j] >= MAXN) break;
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
    for (int d = 1; d < MAXN; d++) {
        for (int i = 1; i * d < MAXN; i++) {
            Ans[d * i] += d * i * S(d);
        }
    }
}

signed main() {
    init();
    int T, N;
    cin >> T;
    while(T--) {
        cin >> N;
        cout << Ans[N] << endl;
    }
}