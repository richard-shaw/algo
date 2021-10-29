//
// Created by 走线大师 on 2021/10/12.
//

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 32003;
int dp[MAXN][62], v[62], p[62], q[62], n, m;
vector<int> sub[62];
int main() {
    for (int i = 0; i < MAXN; i++) for (int j = 0; j < 62; j++) dp[i][j] = 0;
    for (int i = 0; i < 62; i++) sub[i].clear();
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> v[i] >> p[i] >> q[i];
        if (q[i] > 0) sub[q[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i][j-1];
            if (q[j] > 0) continue;
            if (i >= v[j]) dp[i][j] = max(dp[i][j], dp[i - v[j]][j-1] + v[j] * p[j]);
            if (sub[j].size() > 0 && i >= v[j] + v[sub[j][0]]) dp[i][j] = max(dp[i][j], dp[i-v[j]-v[sub[j][0]]][j-1] + v[j]*p[j] + v[sub[j][0]] * p[sub[j][0]]);
            if (sub[j].size() > 1 && i >= v[j] + v[sub[j][1]]) dp[i][j] = max(dp[i][j], dp[i-v[j]-v[sub[j][1]]][j-1] + v[j]*p[j] + v[sub[j][1]] * p[sub[j][1]]);
            if (sub[j].size() > 1 && i >= v[j] + v[sub[j][1]] + v[sub[j][0]]) dp[i][j] = max(dp[i][j], dp[i-v[j]-v[sub[j][0]]-v[sub[j][1]]][j-1] + v[j]*p[j] + v[sub[j][0]] * p[sub[j][0]] + v[sub[j][1]]*p[sub[j][1]]);
        }
    }
    cout << dp[n][m] << endl;
}