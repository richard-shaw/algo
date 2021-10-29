//
// Created by Shaw on 2021/10/18.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
string s;
stack<int> stk;
const int MOD = 1000000007;
int same[800], tmp[800][800][3][3];
void determine() {
    while (!stk.empty()) stk.pop();
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stk.push(i+1);
        else {
            int lft = stk.top();
            same[lft] = i + 1;
            same[i + 1] = lft;
            stk.pop();
        }
    }
}
bool adj(int i, int j) {
    return (i != j) || (i == 0 && j == 0);
}
bool smp(int i, int j) {
    return (i == 0 && j > 0) || (i > 0 && j == 0);
}
int dp(int l, int r, int i, int j) {
    if (~tmp[l][r][i][j]) return tmp[l][r][i][j];
    int ans = 0;
    if (l + 1 == r) ans = smp(i, j);
    else if (same[l] == r) {
        for (int li = 0; li <= 2; li++) {
            for (int rj = 0; rj <= 2; rj++) {
                if (!(adj(i, li) && adj(rj, j) && smp(i, j))) continue;
                ans = (ans + dp(l+1,r-1,li,rj)) % MOD;
            }
        }
    } else {
        ans = 0;
        int r0 = same[l], l0 = same[r];
        for (int j1 = 0; j1 <= 2; j1++) {
            for (int i1 = 0; i1 <= 2; i1++) {
                if (r0 + 1 == l0) {
                    if (!(adj(j1, i1) && smp(i, j1) && smp(i1, j))) continue;
                    ans = (ans + dp(l, r0, i, j1) * dp(l0, r, i1, j)) % MOD;
                } else {
                    if (!(smp(i, j1) && smp(i1, j))) continue;
                    // i-j1, i2-j2, i1-j
                    for (int i2 = 0; i2 <= 2; i2++) {
                        for (int j2 = 0; j2 <= 2; j2++) {
                            if (!(adj(j1, i2) && adj(j2, i1))) continue;
                            int q = (dp(l, r0, i, j1) * dp(l0, r, i1, j)) % MOD;
                            q = (q * dp(r0+1, l0-1, i2, j2)) % MOD;
                            ans = (ans + q) % MOD;
                        }
                    }
                }
            }
        }
    }
    return tmp[l][r][i][j] = ans;
}
signed main() {
    memset(tmp, -1, sizeof(tmp));
    cin >> s;
    determine();
    int ans = 0, n = s.length();
    for (int i = 0; i <= 2; i++) for (int j = 0; j <= 2; j++) ans = (ans + dp(1, n, i, j)) % MOD;
    cout << ans << endl;
}