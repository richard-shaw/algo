/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-05-02 22:35:05
 */
                                     /******************************************************/
//#define MULTI_CASE ::SHAW            /* If this problem only has one case. Erase this line */
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
const int MAXN = 1e6 + 10;
struct treeNode {
    int id, l, r, sum;
} tree[MAXN << 2];
void build(int id, int l, int r) {
    tree[id].id = id, tree[id].l = l, tree[id].r = r, tree[id].sum = 0;
    if (l == r) { return; }
    else {
        build(LL(id), l, MID(l, r));
        build(RR(id), MID(l, r)+1, r);
    }
}
void update(int id, int pos, int val) {
    if (tree[id].l == tree[id].r) {
        tree[id].sum = val;
        return;
    }
    if (pos <= MID(tree[id].l, tree[id].r)) update(LL(id), pos, val);
    else update(RR(id), pos, val);
    tree[id].sum = tree[LL(id)].sum + tree[RR(id)].sum;
}
int query(int id, int l, int r) {
    if (l <= tree[id].l && tree[id].r <= r) return tree[id].sum;
    int sum1 = 0, sum2 = 0, m = MID(tree[id].l, tree[id].r);
    if (l <= m) sum1 = query(LL(id), l, r);
    if (r > m) sum2 = query(RR(id), l, r);
    return sum1 + sum2;
}

void solve(int _case) {
    /** Code here for each Case */
    int N, M, Q;
    cin >> N >> M >> Q;
    build(1, 1, N*M);

    int C = 0;
    for (int i = 0; i < N; i++) {
        string buf;
        cin >> buf;
        for (int j = 0; j < M; j++) {
            int val = buf[j] == '*';
            C += val;
            update(1, j*N+i+1, val);
        }
    }
    while (Q--) {
        int i, j;
        cin >> i >> j;
        int idx = (j-1) * N + i;
        int v = query(1, idx, idx);
        update(1, idx, 1-v);
        C += (v == 1 ? -1 : 1);
        int s0 = query(1, 1, C);
        cout << (C-s0) << endl;
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