//
// Created by 走线大师 on 2021/10/12.
//

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1003;
int dp[MAXN][MAXN*10], N, T[MAXN * 10], C[MAXN * 10], P[MAXN * 10];
string ts, te;
inline int fmt(string t) {
    int pos = t.find(':');
    return atoi(t.substr(0, pos).c_str()) * 60 + atoi(t.substr(pos+1,t.length()-1-pos).c_str());
}
inline int _time() {
    return fmt(te) - fmt(ts);
}
signed main() {
    for (int i = 0; i < MAXN; i++) dp[i][0] = 0;
    cin >> ts >> te >> N;
    int __t = _time();
    for (int i = 1; i <= N; i++) cin >> T[i] >> C[i] >> P[i];
    for (int i = 1; i <= N; i++) {
        for (int t = 0; t <= __t; t++) {
            dp[t][i] = 0;
            for (int k = 0; k * T[i] <= t; k++) {
                if (P[i] != 0 && k > P[i]) break;
                dp[t][i] = max(dp[t - k * T[i]][i - 1] + k * C[i], dp[t][i]);
            }
        }
    }
    cout << dp[__t][N] << endl;
}