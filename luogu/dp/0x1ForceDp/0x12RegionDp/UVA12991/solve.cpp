//
// Created by Shaw on 2021/10/20.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAXN = 4006;
int S[2][MAXN][2], N;
int cost(int i, int j, int k) {
}
// dp[N][k] = min(dp[n][1-k] + cost(n+1, N, k)) (1 <= n <= N - 1)
// if j == N0 cost(i, j, k) = S[1-k][i] * 1 + S[1-k][i+1] * 2 + ... + S[1-k][j] * (j-i+1)
// else cost(i, j, k) = ∑S[1-k][t] * (min(t-i, j-t) + 1)
//              = t <= (i+j)/2: ∑S[1-k][t]t - i∑S[1-k][t] + ..
