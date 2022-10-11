/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-04-08 22:35:03
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

int arr[MAXN];
struct TreeNode {
    int id, l, r, m1, m2;
} tree[MAXN << 2];

void push_up(int id) {
    int a[4] = {
         tree[2*id].m1, tree[2*id].m2, tree[2*id+1].m1, tree[2*id+1].m2
    };
    sort(a, a+4);
    tree[id].m1 = a[0];
    tree[id].m2 = a[1];
}

void build(int id, int l, int r) {
    tree[id].id = id, tree[id].l = l, tree[id].r = r;
    if (l == r) {
        tree[id].m1 = arr[l];
        tree[id].m2 = INF18;
    } else {
        int mid = (l+r) >> 1;
        build(2*id, l, mid);
        build(2*id+1, mid + 1, r);
        push_up(id);
    }
}

pair<int, int> query(int id, int l, int r) {
    if (l <= tree[id].l && tree[id].r <= r) {
        return { tree[id].m1, tree[id].m2 };
    }
    int a[4] = {INF18, INF18, INF18, INF18};
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (l <= mid) {
        pair<int, int> pr = query(2*id, l, r);
        a[0] = pr.first;
        a[1] = pr.second;
    }
    if (r > mid) {
        pair<int, int> pr = query(2*id+1, l, r);
        a[2] = pr.first;
        a[3] = pr.second;
    }
    sort(a, a+4);
    return {a[0], a[1]};
}

int CASE = 0;
void solve(int _case) {
    /** Code here for each Case */
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    build(1, 1, N);
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;

        CASE++;
        if (CASE == 1001) {
            for (int i = l; i <= r; i++) cout << arr[i] << '|';
            cout << endl;
        }

        pair<int, int> pr = query(1, l, r);
        cout << (pr.first | pr.second) << endl;
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