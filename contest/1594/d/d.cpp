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
int fa[MAXN * 2];
pair<int, int> pr[MAXN];
int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void _union(int x, int y) {
    int fx = find(x), fy = find(y);
    fa[fx] = fy;
}

void solve () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i, fa[i + MAXN] = i + MAXN, pr[i].first = pr[i].second = 0;
    bool ok = true;
    while (m--) {
        int i, j;
        string s;
        cin >> i >> j >> s;
        int fi = find(i), fj = find(j), _fi = find(i + MAXN), _fj = find(j + MAXN);
        if (s[0] == 'c') {
            if (fi == _fj && _fi == fj) ok = false;
            else _union(i, j), _union(i+MAXN, j+MAXN);
        } else {
            if (fi == fj && _fi == _fj) ok = false;
            else _union(i, j + MAXN), _union(i + MAXN, j);
        }
    }
    if (!ok) cout << -1 << endl;
    else {
        for (int i = 1; i <= n; i++) {
            int fi = find(i);
            if (fi <= n) pr[fi].first++;
            else pr[fi - MAXN].second++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += max(pr[i].first, pr[i].second);
        cout << ans << endl;
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