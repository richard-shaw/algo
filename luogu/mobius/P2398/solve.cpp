//
// Created by Shaw on 2021/9/20.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 100003
int visit[MAX], prime[MAX], mu[MAX], tot = 0;

void init() {
    memset(visit, 0, sizeof(visit));
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
}

signed main() {
    init();
    int N, Ans = 0;
    cin >> N;
    for (int d = 1; d <= N; d++) {
        int sum = 0;
        for (int k = 1; k <= N / d; k++) {
            sum += mu[k] * (N / d / k) * (N / d / k);
        }
        Ans += d * sum;
    }
    cout << Ans << endl;
}