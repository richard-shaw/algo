/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-09-25 22:35:10
 */
                                     /******************************************************/
#define MULTI_CASE ::SHAW            /* If this problem only has one case. Erase this line */
//#define DEBUG_MODEL ::SHAW         /* If debug for codes. Keep this line                 */
//#define SHOW_CASE_USED_TIME ::SHAW /* If need to show used time for case. Keep this line */
                                     /******************************************************/
#ifndef DEBUG_MODEL//::SHAW
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#endif
#include<bits/stdc++.h>

using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define gcd(x, y) __gcd(x, y)
#define lcm(x, y) (x / __gcd(x, y) * y)
#define LL(x) (x << 1)
#define RR(x) (LL(x) | 1)
#define MID(l, r) ((l + r) >> 1)
#define vec(v, p) vector<int> v(p)
#define f_vec(v, p) vector<double> v(p)
#define set(s) set<int> s; s.clear()
#define map(mp) map<int, int> mp; mp.clear()
#define pb push_back
#define int long long
int ____MOD;
inline int fast_pow(int a, int b) { int base = a, ans = 1; while (b > 0) { if (b & 1) ans = (ans * base) % ____MOD; base = (base * base) % ____MOD; b >>= 1; } return ans; }
inline int inv(int b) { return fast_pow(b, ____MOD-2); }
inline int mod_mul(int a, int b) { return (a * b) % ____MOD; }
inline int mod_div(int a, int b) { return mod_mul(a, inv(b)); }

const int INF9 = 1e9 + 10;
const int INF18 = 1e18 + 10;
const int MOD = ____MOD = 998244353;
const int MAXN = 1e5 + 10;

pair<int, int> p[MAXN];

struct Node {
    int l, r, val;
} T[MAXN<<2][2];

void build(int id, int l, int r) {
    T[id][0].l = T[id][1].l = l, T[id][0].r = T[id][1].r = r;
    if (l == r) {
        T[id][0].val = p[l].second - p[l].first;
        T[id][1].val = p[l].second + p[l].first;
        return;
    }
    int m = (l + r) >> 1;
    build(id<<1, l, m);
    build(id<<1|1, m+1, r);
    T[id][0].val = max(T[id<<1][0].val, T[id<<1|1][0].val);
    T[id][1].val = max(T[id<<1][1].val, T[id<<1|1][1].val);
}

int query(int id, int l, int r, int f) {
    if (l <= T[id][f].l && T[id][f].r <= r) return T[id][f].val;
    int m = (T[id][f].l + T[id][f].r) >> 1;
    int ans = -1e18;
    if (l <= m) ans = max(ans, query(id<<1, l, r, f));
    if (r > m) ans = max(ans, query(id<<1|1, l, r, f));
    return ans;
}

void solve(int _case) {
    /** Code here for each Case */
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i].first;
    for (int i = 1; i <= n; i++) cin >> p[i].second;

    if (n == 1) {
        cout << p[1].first << endl;
        return;
    }

    sort(p+1, p+n+1);
    build(1, 1, n);

    int pos, mx = 1e9;

    for (int i = 1; i < n; i++) {
        int xi = p[i].first, xii = p[i+1].first;

        int cost_left = query(1, 1, i, 0);
        int cost_right = query(1, i+1, n, 1);

        if (cost_left + xi >= cost_right - xi) {
            int ans = 2 * (cost_left + xi);
            if (mx > ans) mx = ans, pos = 2 * xi;
        } else if (cost_left + xii < cost_right - xii) {
            int ans = 2 * (cost_right - xii);
            if (mx > ans) mx = ans, pos = 2 * xii;
        } else {
            int _pos = cost_right - cost_left;
            int ans = cost_right + cost_left;
            if (mx > ans) mx = ans, pos = _pos;
        }
    }
    cout << (pos >> 1);
    if (pos & 1) cout << ".5\n";
    else cout << endl;
}

signed main() {

//    FAST_IO
    int t;
#ifdef MULTI_CASE//::SHAW
    cin >> t;
#else
    t = 1;
#endif
    for (int _case = 1; _case <= t; _case++) {
#ifdef SHOW_CASE_USED_TIME//::SHAW
        clock_t t1 = clock();
#endif
        solve(_case);
#ifdef SHOW_CASE_USED_TIME//:SHAW
        clock_t t2 = clock();
        cout << "Case #" << _case << " used: " << ((double)(t2-t1) / CLOCKS_PER_SEC) << "s" << endl;
#endif
    }
}