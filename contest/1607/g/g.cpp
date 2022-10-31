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
int N, M, a[MAXN], b[MAXN];

void solve () {
    int Ans = 0, Xmax = 0, Xmin = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a[i] >> b[i];
        Ans += (a[i] - b[i]);
        Xmin += max(0ll, M - b[i]);
        Xmax += min(a[i], M);
    }
    Ans += N * M;
    if (Ans - 2 * Xmax >= 0) {
        cout << (Ans - 2 * Xmax) << endl;
        for (int i = 1; i <= N; i++) {
            int a0 = min(a[i], M);
            cout << a0 << ' ' << M - a0 << endl;
        }
    } else if (Ans - 2 * Xmin <= 0) {
        cout << (2 * Xmin - Ans) << endl;
        for (int i = 1; i <= N; i++) {
            int a0 = max(0ll, M - b[i]);
            cout << a0 << ' ' << M - a0 << endl;
        }
    } else {
        cout << (Ans % 2) << endl;
        for (int i = 1; i <= N; i++) Ans -= 2 * max(0ll, M - b[i]);
        for (int i = 1; i <= N; i++) {
            if (Ans >= 2 * (min(a[i], M) - max(0ll, M - b[i]))) {
                int a0 = min(a[i], M);
                cout << a0 << ' ' << M - a0 << endl;
                Ans -= 2 * (a0 - max(0ll, M - b[i]));
            } else {
                int a0 = Ans / 2, b0 = M - a0;
                cout << a0 + max(0ll, M - b[i]) << ' ' << b0 - max(0ll, M - b[i]) << endl;
                Ans -= 2 * a0;
            }
        }
    }
}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}