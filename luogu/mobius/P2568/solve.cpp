//
// Created by Shaw on 2021/9/21.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAXN 10000007
int visit[MAXN], prime[MAXN], mu[MAXN], tot = 0;
void init() {
    memset(visit, 0, sizeof(visit));
    mu[0] = 0, mu[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot && i * prime[j] < MAXN; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for (int i = 2; i < MAXN; i++) mu[i] += mu[i-1];
}

int G(int N) {
    int Ans = 0;
    for (int k = 1; k <= N;) {
        int j = N / (N / k);
        Ans += (N / k) * (N / k) * (mu[j] - mu[k-1]);
        k = j + 1;
    }
    return Ans;
}

signed main() {
    init();
    int N, Ans = 0;
    cin >> N;
    for (int i = 1; i <= tot; i++) {
        int p = prime[i];
        if (p > N) break;
        Ans += G(N / p);
    }
    cout << Ans << endl;
}