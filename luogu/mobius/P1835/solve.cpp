//
// Created by 走线大师 on 2021/9/27.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define max(a, b) (a < b ? b : a)
#define MAXN 47000
int visit[MAXN], prime[MAXN], tot = 0, L, R, pm[1000003];
void init() {
    memset(visit, 0, sizeof(visit));
    memset(pm, 0, sizeof(pm));
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i;
        for (int j = 1; j <= tot && i * prime[j] < MAXN; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

    for (int j = 1; j <= tot; j++) {
        int p = prime[j];
        for (int k = max(L / p, 2); k * p <= R; k++) {

            if (k * p >= L) pm[k * p - L] = 1;
        }
    }
}

signed main() {
    cin >> L >> R;
    L += (L == 1);
    init();
    int Ans = 0;
    for (int i = L; i <= R; i++) {
        Ans += (pm[i - L] == 0);
    }
    cout << Ans << endl;
}