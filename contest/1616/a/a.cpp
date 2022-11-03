/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2022-01-01 18:22:35
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
int res[101];

void solve () {
    int N, a, tot = 0;
    cin >> N;
    memset(res, 0, sizeof(res));
    for (int i = 1; i <= N; i++) {
        cin >> a;
        res[abs(a)]++;
    }
    for (int i = 0; i <= 100; i++) tot += min(res[i], i == 0 ? 1ll : 2ll);
    cout << tot << endl;
}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}