//
// Created by 走线大师 on 2021/10/13.
//
#include <bits/stdc++.h>

using namespace std;
const int INF = -1e9;
const int MAXN = 400000;
int N, dp[2 * MAXN + 1], iq[404], eq[404];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> iq[i] >> eq[i];
    for (int j = 0; j <= 2 * MAXN; j++) dp[j] = INF;
    dp[MAXN] = 0;
    for (int i = 1; i <= N; i++) {
        if (iq[i] >= 0) {
            for (int j = 2*MAXN; j >= iq[i]; j--) dp[j] = max(dp[j], dp[j-iq[i]] + eq[i]);
        } else {
            for (int j = 0; j <= 2*MAXN + iq[i]; j++) dp[j] = max(dp[j], dp[j-iq[i]] + eq[i]);
        }
    }
    int ans = INF;
    for (int i = MAXN; i <= 2 * MAXN; i++) if (dp[i] >= 0) ans = max(ans, dp[i] + i - MAXN);
    cout << ans << endl;
}