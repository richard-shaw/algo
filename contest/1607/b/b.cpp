/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-11-18 13:46:30
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

void solve () {
    int x, n;
    cin >> x >> n;
    if (n == 0) { cout << x << endl; return; }
    int loop = (n - 1) / 4;
    int ans = -4 * loop - 1;
    for (int _n = 1 + 4 * loop + 1; _n <= n; _n++) {
        int id = _n - 4 * loop - 1;
        if (id <= 2) ans += _n;
        else ans -= _n;
    }
    if (x % 2 == 0) x += ans;
    else x -= ans;
    cout << x << endl;
}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}