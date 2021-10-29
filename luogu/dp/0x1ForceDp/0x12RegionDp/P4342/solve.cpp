//
// Created by Shaw on 2021/10/18.
//

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 155;
const int INF = -1e9;
// dp[l][r][1] [l ~ r] 的最大合并结果
// dp[l][r][0] [l ~ r] 的最小合并结果
int tmp[MAXN][MAXN][2], N, V[MAXN * 2];
char op[MAXN * 2];
int dp(int l, int r, int f) {
    if (tmp[l][r][f] != INF) return tmp[l][r][f];
    if (l == r) return V[l];
    if (l + 1 == r) return op[l] == 't' ? (V[l] + V[r]) : (V[l] * V[r]);
    int inf = -INF, Inf = INF;
    for (int pos = l; pos < r; pos++) {
        int lm = dp(l, pos, 0), lM = dp(l, pos, 1), rm = dp(pos+1, r, 0), rM = dp(pos+1, r, 1);
        inf = min(inf, op[pos] == 't' ? (lm + rm) : min(min(lm*rm, lm*rM), min(lM*rm, lM*rM)));
        Inf = max(Inf, op[pos] == 't' ? (lM + rM) : max(max(lm*rm, lm*rM), max(lM*rm, lM*rM)));
    }
    tmp[l][r][1] = Inf;
    tmp[l][r][0] = inf;
    return f == 1 ? Inf : inf;
}
vector<int> vec;
int main() {
    for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) tmp[i][j][0] = tmp[i][j][1] = INF;
    cin >> N;
    int ans = INF;
    for (int i = 1; i <= N; i++) cin >> op[i] >> V[i+1], op[i+N] = op[i];
    for (int i = 2; i <= N; i++) V[i+N] = V[i];
    V[1] = V[N+1];
    for (int i = 1; i <= N; i++) ans = max(ans, dp(i, i + N - 1, 1));
    cout << ans << endl;
    vec.clear();
    for (int i = 1; i <= N; i++) if (dp(i, i + N - 1, 1) == ans) vec.push_back(i == 1 ? N : i-1);
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i == vec.size() - 1) cout << endl;
        else cout << ' ';
    }
}