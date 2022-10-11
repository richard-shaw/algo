/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-12-05 18:20:15
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
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    if (a == b) cout << (a / 2) << endl;
    else if (a >= 3 * b) cout << b << endl;
    else {
        int c = (a - b) / 2;
        cout << c + min((b - c) / 2, (a - 3 * c) / 2) << endl;
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