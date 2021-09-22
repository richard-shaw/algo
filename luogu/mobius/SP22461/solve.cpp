//
// Created by Shaw on 2021/9/17.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
const int MAXN = 1e4 + 4;
int visit[MAXN], prime[MAXN], tot = 0;
void init() {
    memset(visit, 0, sizeof(visit));
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++tot] = i;
        for (int j = 1; j <= tot; j++) {
            if (i * prime[j] >= MAXN) break;
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}
int A(int n, int p) {
    int ans = 1;
    while(ans <= n) {
        ans *= p;
    }
    return (ans / p) % MOD;
}

signed main() {
    init();
    int N, T, Ans;
    cin >> T;
    while (T--) {
        cin >> N;
        Ans = 1;
        for (int j = 1; j <= tot; j++) {
            if (prime[j] > N) break;
            Ans = (Ans * A(N, prime[j])) % MOD;
        }
        while (Ans < 0) Ans += MOD;
        cout << Ans << endl;
    }
}