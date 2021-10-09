//
// Created by 走线大师 on 2021/10/10.
//

#include <bits/stdc++.h>

using namespace std;
int r[202][202], dp[202];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i < N; i++) for (int j = i + 1; j <= N; j++) cin >> r[i][j];
    dp[1] = 0;
    for (int j = 2; j <= N; j++) {
        dp[j] = 1e9;
        for (int i = 1; i < j; i++) dp[j] = min(dp[i] + r[i][j], dp[j]);
    }
    cout << dp[N] << endl;
}