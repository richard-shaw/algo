/* Generated by powerful Codeforces Tool
 * Author: shaw
 * Time: 2022-03-11 22:35:04
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
const int MAXN = 1e4 + 5;
struct quar {
    int l1, r1, l2, r2;
    void set(int _l1, int _r1, int _l2, int _r2) {
        l1 = _l1, r1 = _r1, l2 = _l2, r2 = _r2;
    }
} Ans[MAXN];

int target[103][103], current[103][103], N, M;

void solve () {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string buf;
        cin >> buf;
        for (int j = 1; j <= M; j++) target[i][j] = buf[j-1] - '0', current[i][j] = 0;
    }
    if (target[1][1] == 1) cout << -1 << endl;
    else {
        int q = 0;
        for (int r = N; r >= 1; r--) {
            for (int c = M; c >= 1; c--) {
                if (target[r][c] == current[r][c]) continue;
                else if (target[r][c] == 1) {
                    // 0 -> 1
                    if (c > 1) {
                        Ans[++q].set(r, c-1, r, c);
                        current[r][c-1] = 0;
                    } else {
                        Ans[++q].set(r-1, c, r, c);
                        current[r-1][c] = 0;
                    }
                } else {
                    // 1 -> 0
                    Ans[++q].set(r, c, r, c);
                }
            }
        }
        cout << q << endl;
        for (int k = 1; k <= q; k++) cout << Ans[k].l1 << ' ' << Ans[k].r1 << ' ' << Ans[k].l2 << ' ' << Ans[k].r2 << endl;
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