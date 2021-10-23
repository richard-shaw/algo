//
// Created by 走线大师 on 2021/10/11.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define _max(x, y) (x < y ? y : x)
#define __d(c) (c == 'A' ? 0 : (c == 'T' ? 1 : (c == 'G' ? 2 : 3)))
#define max(x, y, z) (_max(_max(x, y), z))
const int MAXN = 3004;
const int INF = 0x7ffffffffffffff;
int dp[MAXN][MAXN][3], A, B, n, m, _d[4][4];
string a, b;
inline int d(char c1, char c2) { return _d[__d(c1)][__d(c2)]; }
signed main() {
    cin >> a >> b, n = a.length(), m = b.length();
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cin >> _d[i][j];
    cin >> A >> B;
    for (int i = 0; i < MAXN; i++) dp[0][i][0] = dp[0][i][2] = -INF, dp[0][i][1] = -A - B * (i-1);
    for (int i = 0; i < MAXN; i++) dp[i][0][0] = dp[i][0][1] = -INF, dp[i][0][2] = -A - B * (i-1);
    dp[0][0][0] = 0, dp[0][0][1] = dp[0][0][2] = -INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j][0] = max(dp[i-1][j-1][0], dp[i-1][j-1][1], dp[i-1][j-1][2]) + d(a[i-1], b[j-1]);
            dp[i][j][1] = max(dp[i][j-1][0]-A, dp[i][j-1][1]-B, dp[i][j-1][2]-A);
            dp[i][j][2] = max(dp[i-1][j][0]-A, dp[i-1][j][1]-A, dp[i-1][j][2]-B);
        }
    }
    cout << max(dp[n][m][0], dp[n][m][1], dp[n][m][2]) << endl;
}