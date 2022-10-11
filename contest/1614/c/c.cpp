/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-12-03 22:13:10
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
    int ans = 1, base = a;
    while (b > 0) {
        if (b & 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int N, M;
    cin >> N >> M;
    int rs = 0, x;
    while (M--) {
        cin >> x >> x >> x;
        rs |= x;
    }
    cout << (rs * ex_pow(2, N - 1)) % MOD << endl;
}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}