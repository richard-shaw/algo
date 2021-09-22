//
// Created by Shaw on 2021/9/17.
//
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 1;
const int MAX_D = 240;
int visit[maxn], prime[maxn], d[maxn], tot = 0, Q[maxn];

int D(int n, int p) {
    int Ans = 0;
    while (n % p == 0) {
        Ans ++;
        n /= p;
    }
    return Ans;
}

void init() {
    memset(visit, 0, sizeof(visit));
    memset(Q, 0, sizeof(Q));
    d[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (visit[i] == 0) prime[++tot] = i, d[i] = 2;
        for (int j = 1; j <= tot; j++) {
            if (i * prime[j] >= maxn) break;
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                int d0 = D(i, prime[j]);
                d[i * prime[j]] = d[i] / (d0 + 1) * (d0 + 2);
                break;
            } else {
                d[i * prime[j]] = d[i] * d[prime[j]];
            }
        }
    }

    for (int i = 1; i <= tot && prime[i] <= MAX_D; i++) {
        for (int j = i + 1; j <= tot && prime[j] <= MAX_D; j++) {
            Q[prime[i] * prime[j]] = 1;
        }
    }
}

int main() {
    init();
    int cnt = 0;
    for (int i = 1; i < maxn; i++) {
        if (Q[d[i]]) {
            cnt++;
            if (cnt % 9 == 0) cout << i << endl;
        }
    }
}