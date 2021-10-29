//
// Created by 走线大师 on 2021/10/20.
//

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 4003;
const int inf = 0x7fffffffffffffff;
int tmp[MAXN][2], s[MAXN][2][2], N;
int cost(int l, int r, int k) {
    if (l == 1 && r == N) return inf;
    if (l == 1) {
        return (r+1) * (s[r][1-k][0] - s[l-1][1-k][0]) - (s[r][1-k][1] - s[l-1][1-k][1]);
    } else if (r == N) {
        return (s[r][1-k][1] - s[l-1][1-k][1]) - (s[r][1-k][0] - s[l-1][1-k][0]) * (l - 1);
    } else {
        int mid = (l + r) >> 1;
        return (s[mid][1-k][1] - s[l-1][1-k][1] - (s[mid][1-k][0] - s[l-1][1-k][0]) * (l - 1))
        + ((r + 1) * (s[r][1-k][0] - s[mid][1-k][0]) - (s[r][1-k][1] - s[mid][1-k][1]));
    }
}
int dp(int n, int k) {
    if (~tmp[n][k]) return tmp[n][k];
    if (n == 0) return 0;
    int ans = inf;
    for (int m = 0; m < n; m++) {
        ans = min(dp(m, 1-k) + cost(m+1, n, k), ans);
    }
    return tmp[n][k] = ans;
}

void solve(int index) {
    cin >> N;
//    for (int i = 0; i <= N; i++) tmp[i][0] = tmp[i][1] = -1, s[i][0][0] = s[i][0][1] = s[i][1][0] = s[i][1][1] = 0;
    memset(tmp, -1, sizeof(tmp));
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= N; i++) cin >> s[i][0][0] >> s[i][1][0];
    for (int i = 1; i <= N; i++) {
        s[i][0][1] = s[i-1][0][1] + (s[i][0][0] * i);
        s[i][1][1] = s[i-1][1][1] + (s[i][1][0] * i);
        s[i][0][0] += s[i-1][0][0];
        s[i][1][0] += s[i-1][1][0];
    }
    int ans = min(dp(N, 0), dp(N, 1));
    cout << "Case #" << index << ": " << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
