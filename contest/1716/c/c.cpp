/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: who_cuts_the_moonlight
 * Time: 2022-08-04 22:35:11
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
#define endl "\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
int ____MOD;
inline int fast_pow(int a, int b) { int base = a, ans = 1; while (b > 0) { if (b & 1) ans = (ans * base) % ____MOD; base = (base * base) % ____MOD; b >>= 1; } return ans; }
inline int inv(int b) { return fast_pow(b, ____MOD-2); }
inline int mod_mul(int a, int b) { return (a * b) % ____MOD; }
inline int mod_div(int a, int b) { return mod_mul(a, inv(b)); }

const int INF9 = 1e9 + 10;
const int INF18 = 1e18 + 10;
const int MOD = ____MOD = 998244353;
const int MAXN = 2e5 + 10;

struct treeNode {
    int l, r, mx;
} tree[2][MAXN << 3];
int A[2][MAXN], B[2][2][MAXN];
void build(int f, int id, int l, int r, int N) {
    tree[f][id].l = l, tree[f][id].r = r;
    if (l == r) {
        if (l <= N) tree[f][id].mx = B[f][0][l-1];
        else tree[f][id].mx = B[f][1][2*N-l];
    } else {
        int m = (l + r) >> 1;
        build(f, 2*id, l, m, N);
        build(f, 2*id+1, m+1, r, N);
        tree[f][id].mx = max(tree[f][2*id].mx, tree[f][2*id+1].mx);
    }
}
int query(int f, int id, int l, int r) {
    if (l <= tree[f][id].l && tree[f][id].r <= r) return tree[f][id].mx;
    int m = (tree[f][id].l + tree[f][id].r) >> 1;
    int m1 = -INF18, m2 = -INF18;
    if (l <= m) m1 = query(f, 2*id, l, r);
    if (r > m) m2 = query(f, 2*id+1, l, r);
    return max(m1, m2);
}
int sv(int i, int j, int t, int n) {
    int k = 2 * (n - j) - 1, delta = 0;
    int l = 1 + j, r = 2 * n - j;
    if (i % 2 == 0) {
        delta = max(0ll, query(0, 1, l+1, r) - query(0, 1, l, l));
    } else {
        delta = max(0ll, query(1, 1, l, r-1) - query(1, 1, r, r));
    }
    return k + delta;
}
void solve(int _case) {
    /** Code here for each Case */
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> A[0][i];
    for (int j = 0; j < n; j++) cin >> A[1][j];
    for (int i = 0; i < n; i++) B[0][0][i] = A[0][i] - i;
    for (int i = 0; i < n; i++) B[0][1][n-i-1] = A[1][n-i-1] - n - i;
    for (int i = 0; i < n; i++) B[1][1][i] = A[1][i] - i;
    for (int i = 0; i < n; i++) B[1][0][n-i-1] = A[0][n-i-1] - n - i;
    build(0, 1, 1, 2 * n, n);
    build(1, 1, 1, 2 * n, n);

    int ans = INF18;
    int t = 0, i = 0, j = 0;
    for (int cs = 1; cs <= 2 * n; cs++) {
        if (t < A[i][j]) t = A[i][j] + 1;
        if ((i % 2) ^ (j % 2) == 0) ans = min(ans, t + sv(i, j, t, n));
        t ++;
        if (i == 0 && j % 2 == 0) i++;
        else if (i == 0 && j % 2 == 1) j++;
        else if (i == 1 && j % 2 == 0) j++;
        else i--;
    }
    cout << ans << endl;
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