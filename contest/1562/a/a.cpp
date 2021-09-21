/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-08-26 22:35:02
 */

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
    int l, r;
    cin >> l >> r;
    if (r-l<l) cout << (r-l) << endl;
    else {
        if (r % 2 == 1) cout << r/2<< endl;
        else cout << (r/2-1)<< endl;
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