/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-05-14 17:35:12
 */
                                     /******************************************************/
//#define MULTI_CASE ::SHAW            /* If this problem only has one case. Erase this line */
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
struct treeNode{
    int l, r, sum, total;
} tree[2][MAXN << 2];
void build(int f, int id, int l, int r) {
    tree[f][id].l = l, tree[f][id].r = r;
    if (l == r) tree[f][id].sum = tree[f][id].total = 0;
    else {
        int m = (l + r) >> 1;
        build(f, 2*id, l, m);
        build(f, 2*id+1, m+1, r);
        tree[f][id].sum = tree[f][2*id].sum + tree[f][2*id+1].sum;
        tree[f][id].total = tree[f][2*id].total + tree[f][2*id+1].total;
    }
}
void update(int f, int id, int pos, int x) {
    if (tree[f][id].l == pos && tree[f][id].r == pos) {
        if (x == 1) {
            tree[f][id].sum += 1;
            tree[f][id].total = 1;
        } else {
            tree[f][id].sum -= 1;
            tree[f][id].total = tree[f][id].sum > 0;
        }
    }
    else {
        int m = (tree[f][id].l + tree[f][id].r) >> 1;
        if (pos <= m) update(f, 2*id, pos, x);
        else update(f, 2*id+1, pos, x);
        tree[f][id].sum = tree[f][2*id].sum + tree[f][2*id+1].sum;
        tree[f][id].total = tree[f][2*id].total + tree[f][2*id+1].total;
    }
}

int query(int f, int id, int l, int r) {
    if (l <= tree[f][id].l && tree[f][id].r <= r) return tree[f][id].total;
    int m = (tree[f][id].l + tree[f][id].r) >> 1, s1 = 0, s2 = 0;
    if (l <= m) s1 = query(f, 2*id, l, r);
    if (r > m) s2 = query(f, 2*id+1, l, r);
    return s1 + s2;
}


void solve(int _case) {
    /** Code here for each Case */
    int n, q;
    cin >> n >> q;
    build(0, 1, 1, n);
    build(1, 1, 1, n);
    while (q--) {
        int op, x1, x2, y1, y2;
        cin >> op;
        if (op <= 2) {
            cin >> x1 >> y1;
            update(0, 1, x1, 2-op);
            update(1, 1, y1, 2-op);
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
            if (query(0, 1, x1, x2) == (x2-x1+1) || query(1, 1, y1, y2) == (y2-y1+1)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }


}

signed main() {

    FAST_IO
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