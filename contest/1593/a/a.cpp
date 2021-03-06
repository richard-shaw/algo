/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-10-13 22:35:01
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

int sv(int a, int b, int c, int i) {
    int mx = max(a, max(b, c));
    int n[3] = {a,b,c};
    if (mx == n[i-1]) {
        int eq = 0;
        for (int j = 0; j < 3; j++) eq += (n[j] == mx);
        if (eq >= 2) return 1;
        else return 0;
    } else {
        return mx + 1 - n[i-1];
    }
}

void solve () {
    int a, b, c;
    cin >> a >> b >> c;
    cout << sv(a,b,c,1) << ' ' << sv(a,b,c,2) << ' ' << sv(a,b,c,3) << endl;
}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}