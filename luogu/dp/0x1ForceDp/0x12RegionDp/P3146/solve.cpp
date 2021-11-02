//
// Created by Shaw on 2021/10/18.
//

#include <bits/stdc++.h>

using namespace std;
// dp[l][r] [l,r]能全部合并的最大值
const int MAXN = 250;
int tmp[MAXN][MAXN], N, arr[MAXN];
int dp(int l, int r) {
    if (~tmp[l][r]) return tmp[l][r];
    if (l == r) return arr[l];
    int ans = 0;
    for (int pos = l; pos < r; pos++) {
        if (dp(l, pos) == dp(pos+1, r)) {
            ans = max(ans, dp(pos+1, r) + 1);
        }
    }
    return tmp[l][r] = ans;
}


int main() {
    memset(tmp, -1, sizeof(tmp));
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    int ans = 0;
    for (int i = 1; i <= N; i++) for (int j = i; j <= N; j++) ans = max(ans, dp(i, j));
    cout << ans << endl;
}