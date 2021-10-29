//
// Created by 走线大师 on 2021/10/15.
//

#include <bits/stdc++.h>

using namespace std;
// 本地MAXN开110可以，洛谷RE。不确定是否为未知bug
const int MAXN = 300;
int N, tmp[2][MAXN][MAXN * 2], arr[MAXN], sum[2 * MAXN];
int dp(int f, int l, int r) {
    if (~tmp[f][l][r]) return tmp[f][l][r];
    if (l == r) return 0;
    int inf = 1e9, Inf = -1e9;
    for (int k = 0; k <= r - l - 1; k++) {
        if (f == 0) inf = min(inf, dp(f, l, l + k) + dp(f, l + k + 1, r) + sum[r] - sum[l-1]);
        else Inf = max(Inf, dp(f, l, l + k) + dp(f, l + k + 1, r) + sum[r] - sum[l-1]);
    }
    return tmp[f][l][r] = f == 0 ? inf : Inf;
}

int main() {
    memset(tmp, -1, sizeof(tmp));
    memset(sum, 0, sizeof(sum));
    cin >> N;
    for (int i = 1; i <= N; i++) {cin >> arr[i]; sum[i] = sum[i-1] + arr[i];}
    for (int i = N + 1; i <= 2 * N; i++) sum[i] = sum[i-1] + arr[i-N];
    int inf = 1e9, Inf = -1e9;
    for (int k = 1; k <= N; k++) {
        inf = min(inf, dp(0, k, N + k - 1));
        Inf = max(Inf, dp(1, k, N + k - 1));
    }
    cout << inf << endl;
    cout << Inf << endl;
}