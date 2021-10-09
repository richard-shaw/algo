//
// Created by 走线大师 on 2021/10/10.
//

#include <bits/stdc++.h>
using namespace std;
int tmp[30002][26], n, m, v[26], w[26];
int dp(int N, int M) {
    if (tmp[N][M] != -1) return tmp[N][M];
    if (M == 1) return tmp[N][M] = v[M] >= N ? 0 : v[1] * w[1];
    int ans = dp(N, M - 1);
    if (N >= v[M]) ans = max(ans, dp(N - v[M], M - 1) + v[M] * w[M]);
    return tmp[N][M] = ans;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> v[i] >> w[i];
    for (int i = 1; i < 30002; i++) for (int j = 0; j < 26; j++) tmp[i][j] = -1;
    cout << dp(n, m) << endl;
}