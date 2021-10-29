//
// Created by 走线大师 on 2021/10/16.
//

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 310;
int L[MAXN], R[MAXN], tmp[MAXN][MAXN * 2], N;
int dp(int l, int r) {
    if (~tmp[l][r]) return tmp[l][r];
    if (l == r) return 0;
    int ans = 0;
    for (int k = l; k < r; k++) {
        ans = max(ans, dp(l, k) + dp(k+1, r) + L[l] * R[k] * R[r]);
    }
    return tmp[l][r] = ans;
}

int main() {
    memset(tmp, -1, sizeof(tmp));
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> L[i];
        L[i + N] = L[i];
    }
    for (int j = 1; j < 2 * N; j++) {
        R[j] = L[j+1];
    }
    R[2*N] = L[1];
    int ans = 0;
    for (int l = 1; l <= N; l++) ans = max(ans, dp(l, l + N - 1));
    cout << ans << endl;
}
