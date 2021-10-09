//
// Created by 走线大师 on 2021/10/10.
//

#include <bits/stdc++.h>
using namespace std;
int tmp[20002][33], v[33], V, n;
int dp(int s, int i) {
    if (tmp[s][i] != -1) return tmp[s][i];
    if (i == 1) return tmp[s][i] = s >= v[1] ? s - v[1] : s;
    int ans = dp(s, i - 1);
    if (s >= v[i]) ans = min(ans, dp(s - v[i], i - 1));
    return tmp[s][i] = ans;
}
int main() {
    for (int i = 0; i < 20002; i++) for (int j = 0; j < 33; j++) tmp[i][j] = -1;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    cout << dp(V, n) << endl;
}