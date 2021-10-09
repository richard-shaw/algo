/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-10-09 10:27:19
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
const int MAXN = 2e5 + 9;
const int MOD = 1e9 + 7;
int ex_pow(int a, int b) {
    int base = a, ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * base) % MOD;
        base = (base * base ) % MOD;
        b >>= 1;
    }
    return ans;
}
void solve () {
    int k, ss = 1;
    cin >> k;
    int q = (ss << k) - 2;
    cout << (6 * ex_pow(4, q)) % MOD << endl;
}

signed main() {
    fast_stream();
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}