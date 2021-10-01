#include <bits/stdc++.h>
using namespace std;
#define MAXN 10004
#define W 1000
#define inf 1145141919
int dp[MAXN][2 * W + 1], arr[MAXN];
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= 2 * W; j++) dp[i][j] = inf;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    dp[1][0] = dp[1][arr[1]] = arr[1];
    for (int i = 1; i < n; i++) {
        for (int dt = 0; dt <= 2 * W; dt++) {
            int d = dp[i][dt], l = arr[i+1];
            if (d == inf) continue;
            if (l > dt) dp[i+1][0] = min(dp[i+1][0], d + l - dt);
            else dp[i+1][dt-l] = min(dp[i+1][dt-l], d);
            if (l + dt < 0 || l + dt > 2 * W) continue;
            if (l > d - dt) dp[i+1][l+dt] = min(dp[i+1][l+dt], l+dt);
            else dp[i+1][l+dt] = min(dp[i+1][l+dt], d);
        }
    }
    int ans = inf;
    for (int j = 0; j <= 2 * W; j++) ans = min(ans, dp[n][j]);
    cout << ans << endl;
}
int main() { int t; cin >> t; while (t--) solve(); }