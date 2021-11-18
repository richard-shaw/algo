/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-11-02 20:05:13
 */
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;
void fast_stream() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define int long long
const int INF = 0x7fffffffffffffff;

const int MOD = 998244353;
const int MAXN = 1e5 + 9;
int arr[MAXN], dp[2][MAXN], N;
vector<int> st[2];

void solve () {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    int Ans = 0;
    for (int r = N; r >= 1; r--) {
        int k = r & 1;
        dp[k][arr[r]] = 1;
        st[k].push_back(arr[r]);
        int last = arr[r];
        for (int y : st[1 - k]) {
            int m = (arr[r] - 1) / y + 1;
            int x = arr[r] / m;
            dp[k][x] += dp[1-k][y];
            Ans = (Ans + (m - 1) * r * dp[1-k][y]) % MOD;
            if (x != last) {
                st[k].push_back(x);
                last = x;
            }
            dp[1-k][y] = 0;
        }
        st[1-k].clear();
    }
    for (int y : st[1]) {
        dp[1][y] = 0;
    }
    st[1].clear();
    cout << Ans << endl;
}

signed main() {
    fast_stream();
    for (int i = 0; i < MAXN; i++) dp[0][i] = dp[1][i] = 0;
    st[0].clear(), st[1].clear();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}