/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-10-08 23:05:02
 */
//#pragma GCC optimize("Ofast", "inline", "-ffast-math")
//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;
void fast_stream() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define int long long
#define imp 200001
#define cre 200002
const int INF = 0x7fffffffffffffff;
const int MAXN = 6;//2e5 + 9;
int fa[2 * MAXN + 1], tq[MAXN];
map<int, int> mp;

int find (int x) {
    if (x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}

void _union(int x, int y) {
    int fx = find(x), fy = find(y);
    fa[fx] = fy;
}

void solve () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i, fa[i + MAXN] = i + MAXN;
    bool ok = true;
    while (m--) {
        int i, j;
        string s;
        cin >> i >> j >> s;
        if (s == "crewmate") {
            if (find(i) == find(j + MAXN) && find(j) == find(i + MAXN)) ok = false;
            else _union(i, j), _union(i+MAXN, j + MAXN);
        } else {
            if (find(i) == find(j) && find(i + MAXN) == find(j + MAXN)) ok = false;
            else _union(i, j + MAXN), _union(i + MAXN, j);
        }
    }
    if (!ok) {cout << -1 << endl; return;}
    int q1 = 0, q2 = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) < MAXN) q1++;
        else q2++;
    }
    cout << (q1 < q2 ? q2 : q1) << endl;
}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}