//
// Created by 走线大师 on 2021/10/10.
//

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 404;
int v[MAXN], w[MAXN], c[MAXN], tmp[MAXN][MAXN][54];
int dp(int V, int W, int i) {
    if (~tmp[V][W][i]) return tmp[V][W][i];
    if (i == 1) return tmp[V][W][1] = (V >= v[1] && W >= w[1]) ? c[1] : 0;
    int ans = dp(V, W, i - 1);
    if (V >= v[i] && W >= w[i]) ans = max(ans, dp(V - v[i], W - w[i], i - 1) + c[i]);
    return tmp[V][W][i] = ans;
}

int main() {
    for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) memset(tmp[i][j], -1, sizeof(tmp[i][j]));
    int V, W, N;
    cin >> V >> W >> N;
    for (int i = 1; i <= N; i++) cin >> v[i] >> w[i] >> c[i];
    cout << dp(V, W, N) << endl;
}