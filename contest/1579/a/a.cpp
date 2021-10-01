/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-09-28 22:35:02
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
    string s;
    cin >> s;
    int cnt[3];
    cnt[0] = cnt[1] = cnt[2] = 0;
    for (int i = 0; i < s.length(); i++) cnt[s[i] - 'A']++;
    if (cnt[0] + cnt[2] == cnt[1]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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