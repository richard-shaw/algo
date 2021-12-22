/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-12-16 17:46:48
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
const int MAXN = 4e4 + 9;
int y[MAXN], N, x[MAXN];
void solve () {
    //         2 * Y + (y[i-1] - y[i]) * N * (N + 1)
    //  x[i] = -------------------------------------
    //                N * N * (N + 1)
    cin >> N;
    int Y = 0;
    for (int i = 1; i <= N; i++) cin >> y[i], Y += y[i];
    y[0] = y[N];

    bool ok = true;
    for (int i = 1; i <= N; i++) {
        int up = 2 * Y + (y[i-1] - y[i]) * N * (N + 1);
        int down = N * N * (N + 1);
        if (up % down != 0) { ok = false; break;}
        x[i] = up / down;
        if (x[i] <= 0 || x[i] > 1e9) { ok = false; break; }
    }
    cout << (ok ? "YES" : "NO") << endl;
    if (ok) {
        for (int i = 1; i <= N; i++) {
            cout << x[i];
            if (i == N) cout << endl;
            else cout << ' ';
        }
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