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

void solve () {
    int s, n, k;
    cin >> s >> n >> k;
    if (k > s) cout << "NO" << endl;
    else if (k == s) cout << "YES" << endl;
    else {
        int s_left = (n / k) * 2 * k + n % k;
        if (s_left <= s) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}