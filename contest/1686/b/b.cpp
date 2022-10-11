/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-05-26 01:35:11
 */
                                     /******************************************************/
#define MULTI_CASE ::SHAW            /* If this problem only has one case. Erase this line */
#define DEBUG_MODEL ::SHAW         /* If debug for codes. Keep this line                 */
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
int arr[MAXN];

struct tree_node {
    int l, r, lazy, sum;
    void update(int lz) {
        lazy = lz;
        sum = (r - l + 1) * lz;
    }
} tree[MAXN << 2];
void push_up(int id) {
    tree[id].sum = tree[LL(id)].sum + tree[RR(id)].sum;
}
void push_down(int id) {
    if (tree[id].lazy != -1) {
        tree[LL(id)].update(tree[id].lazy);
        tree[RR(id)].update(tree[id].lazy);
        push_up(id);
        tree[id].lazy = -1;
    }
}

void build(int id, int l, int r) {
    tree[id].l = l, tree[id].r = r, tree[id].lazy = -1;
    tree[id].sum = 0;
    if (l != r) {
        int m = MID(l, r);
        build(LL(id), l, m);
        build(RR(id), m+1, r);
    }
}

void update(int id, int l, int r, int x) {
    if (l <= tree[id].l && tree[id].r <= r) tree[id].update(x);
    else {
        push_down(id);
        int mid = MID(tree[id].l, tree[id].r);
        if (l <= mid) update(LL(id), l, r, x);
        if (r > mid) update(RR(id), l, r, x);
        push_up(id);
    }
}

int query(int id, int l, int r) {
    if (l <= tree[id].l && tree[id].r <= r) return tree[id].sum;
    int mid = MID(tree[id].l, tree[id].r);
    int s1 = 0, s2 = 0;
    push_down(id);
    if (l <= mid) s1 = query(LL(id), l, r);
    if (r > mid) s2 = query(RR(id), l, r);
    push_up(id);
    return s1 + s2;
}


void solve(int _case) {
    /** Code here for each Case */
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int lg = query(1, arr[i]+1, n);
        if (lg % 2 == 1) { cnt++, update(1, 1, n, 0); }
        else update(1, arr[i], arr[i], 1);
    }
    cout << cnt << endl;
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