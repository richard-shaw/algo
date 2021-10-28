//
// Created by 走线大师 on 2021/10/28.
//

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
using namespace std;
#define int long long
const int INF = 1e9;
int dp[12][1 << 12], g[12][12], n, m, root, Ans = INF, P[1<<12][1<<12];
vector<int> Q[1 << 12], A[1<<12];

vector<int> idx(int s) {
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (s & 1) res.push_back(i);
        s >>= 1;
    }
    return res;
}

int pay(int s, int k) {
    int ans = 0;
    for (int kii : A[k]) {
        int M = INF;
        for (int sii : A[s]) {
            if (g[sii][kii] < INF) M = min(M, g[sii][kii]);
        }
        ans += M;
    }
    return ans;
}

signed main() {
    cin >> n >> m;
    for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) g[i][j] = INF;
    while (m--) {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        g[u][v] = g[v][u] = min(g[u][v], d);
    }
    for (int i = 0; i < (1 << 12); i++) {
        Q[i].clear();
        A[i].clear();
        int s = i;
        for (int j = 0; j < n; j++) {
            if (s & 1) A[i].push_back(j);
            s >>= 1;
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (i & j) continue;
            Q[i].push_back(j);
            P[i][j] = pay(i, j);
        }
    }
    for (root = 0; root < n; root++) {
        for (int i = 0; i < 12; i ++) for (int j = 0; j < (1 << 12); j++) dp[i][j] = INF;
        dp[0][1<<root] = 0;
        for (int i = 1; i < n; i++) {
            for (int s = 1; s < (1 << n); s++) {
                for (int k : Q[s]) {
                    dp[i][s | k] = min(dp[i][s | k], dp[i-1][s] + P[s][k] * i);
                }
            }
        }
        for (int i = 0; i < n; i++) Ans = min(Ans, dp[i][(1 << n) - 1]);
    }
    cout << Ans << endl;
}