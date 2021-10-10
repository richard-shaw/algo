//
// Created by 走线大师 on 2021/10/10.
//

#include <bits/stdc++.h>
#define lp(x) for (x = 0; x < MAXN; x++)
using namespace std;
const int MAXN = 41;
int tmp[MAXN][MAXN][MAXN][MAXN], a[MAXN * 9], N, M, b[5];
void init() {
    int i, j, k, l;
    lp(i) lp(j) lp(k) lp(l) tmp[i][j][k][l] = -1;
}
int dp(int i, int j, int k, int t) {
    if (~tmp[i][j][k][t]) return tmp[i][j][k][t];
    if (i == 0 && j == 0 && k == 0 && t == 0) return tmp[i][j][k][t] = a[1];
    int ans = 0;
    if (i >= 1) ans = max(ans, dp(i-1,j,k,t));
    if (j >= 1) ans = max(ans, dp(i,j-1,k,t));
    if (k >= 1) ans = max(ans, dp(i,j,k-1,t));
    if (t >= 1) ans = max(ans, dp(i,j,k,t-1));
    return tmp[i][j][k][t] = ans + a[i+2*j+3*k+4*t+1];

}
int main() {
    init();
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> a[i];
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= M; i++) {int kind; cin >> kind; b[kind]++;}
    cout << dp(b[1], b[2], b[3], b[4]) << endl;
}