//
// Created by 走线大师 on 2022/6/28.
//

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 203;
int dp[MAXN][MAXN], X[MAXN], Y[MAXN], P[MAXN];

int main() {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i] >> P[i];
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
        int L = abs(X[i]-X[j]) + abs(Y[i]-Y[j]);
        if (i == j) dp[i][j] = 0;
        else dp[i][j] = (L - 1) / P[i] + 1;
    }
    for (int k = 1; k <= N; k++) for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
        dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
    int ans = 1e9;
    for (int i = 1; i <= N; i++) {
        int cost = 0;
        for (int j = 1; j <= N; j++) cost = max(cost, dp[i][j]);
        ans = min(ans, cost);
    }
    cout << ans << endl;
}