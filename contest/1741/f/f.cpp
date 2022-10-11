/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: who_cuts_the_moonlight
 * Time: 2022-10-11 22:35:11
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

const int maxn = 2e5 + 10;
const int _M = 6e5 + 10;
typedef pair<int, pair<int, int>> TP;
struct Seg {
    int l, r, c;
    void init(int _l, int _r, int _c) { l = _l, r = _r, c = _c; }
} seg[maxn];
class Discretization {
private:
    vector<int> IDX;
public:
    Discretization() {
        IDX.clear();
    }
    void clear() {
        IDX.clear();
    }
    void add_num(int x) {
        IDX.push_back(x);
    }
    void run() {
        sort(IDX.begin(), IDX.end());
        IDX.erase(unique(IDX.begin(), IDX.end()), IDX.end());
    }
    int get_trans(int x) {
        return lower_bound(IDX.begin(), IDX.end(), x) - IDX.begin();
    }
    int get_orig(int id) {
        return IDX[id];
    }
    int size() {
        return IDX.size();
    }
} D;
struct Node {
    int l, r, c_c, c1, c2, lazy_c;
    void update(int lc) {
        lazy_c = lc;
        if (c1 == lc || c2 == lc) return;
        if (c_c == 2) return;
        else if (c_c == 1) {
            if (c1 == lc) return;
            else c_c = 2, c2 = lc;
        } else {
            c_c = 1;
            c1 = lc;
        }
    }
} tree[maxn << 5];
void push_down(int id) {
    if (tree[id].lazy_c) {
        tree[LL(id)].update(tree[id].lazy_c);
        tree[RR(id)].update(tree[id].lazy_c);
        tree[id].lazy_c = 0;
    }
}
void push_up(int id, int cid) {
    tree[id].c_c = tree[cid].c_c;
    tree[id].c1 = tree[cid].c1;
    tree[id].c2 = tree[cid].c2;
}
void push_up(int id) {
    int cl = tree[LL(id)].c_c, cr = tree[RR(id)].c_c;
    if (cl >= 2) push_up(id, LL(id));
    else if (cr >= 2) push_up(id, RR(id));
    else if (cl == 1 && cr == 1) {
        tree[id].c_c = 2;
        tree[id].c1 = tree[LL(id)].c1;
        tree[id].c2 = tree[RR(id)].c1;
    }
    else if (cl == 1) push_up(id, LL(id));
    else if (cr == 1) push_up(id, RR(id));
    else tree[id].c_c = tree[id].c1 = tree[id].c2 = 0;
}
void build(int id, int l, int r) {
    tree[id].l = l, tree[id].r = r;
    tree[id].c_c = tree[id].c1 = tree[id].c2 = tree[id].lazy_c = 0;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(LL(id), l, m);
    build(RR(id), m + 1, r);
}
void update(int id, int l, int r, int c) {
    push_down(id);
    if (l <= tree[id].l && tree[id].r <= r) tree[id].update(c);
    else {
        int m = MID(tree[id].l, tree[id].r);
        if (l <= m) update(LL(id), l, r, c);
        if (r > m ) update(RR(id), l, r, c);
        push_up(id);
    }
}
TP query(int id, int l, int r) {
    push_down(id);
    if (l <= tree[id].l && tree[id].r <= r) {
        return {tree[id].c_c, {tree[id].c1, tree[id].c2} };
    }
    int m = MID(tree[id].l, tree[id].r);
    int c_c = 0;
    int c_[] = {0, 0, 0, 0};
    if (l <= m) {
        TP an1 = query(LL(id), l, r);
        if (an1.first >= 1) c_[c_c++] = an1.second.first;
        if (an1.first >= 2) c_[c_c++] = an1.second.second;
    }
    if (c_c < 2 && r > m) {
        TP an2 = query(RR(id), l, r);
        if (an2.first >= 1) c_[c_c++] = an2.second.first;
        if (c_c < 2 && an2.first >= 2) c_[c_c++] = an2.second.second;
    }
    return {c_c, {c_[0], c_[1]}};
}

int qy(int L, int R, int c, int pos, bool right) {
    while (L + 1 < R) {
        int M = MID(L, R);
        TP tp;
        if (right) tp = query(1, pos, M);
        else tp = query(1, M, pos);

        if (tp.first >= 2)  {
            if (right) R = M;
            else L = M;
        } else if (tp.first == 1 && tp.second.first != c) {
            if (right) R = M;
            else L = M;
        } else {
            if (right) L = M + 1;
            else R = M;
        }
    }
    if (L < R) {
        if (right) {
            TP tp = query(1, pos, L);
            if (tp.first >= 2) L = L;
            else if (tp.first == 1 && tp.second.first != c) L = L;
            else L = R;
        } else {
            TP tp = query(1, R, pos);
            if (tp.first >= 2) L = R;
            else if (tp.first == 1 && tp.second.first != c) L = R;
            else L = L;
        }
    }
    return abs(D.get_orig(L) - D.get_orig(pos));
}
void solve(int _case) {
    /** Code here for each Case */
    D.clear();
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r, c; cin >> l >> r >> c;
        seg[i].init(l, r, c);
        D.add_num(l-1), D.add_num(l), D.add_num(l+1);
        D.add_num(r-1), D.add_num(r), D.add_num(r+1);
    }
    D.run();

    build(1, 1, _M);
    for (int i = 1; i <= n; i++) update(1, D.get_trans(seg[i].l), D.get_trans(seg[i].r), seg[i].c);
    for (int i = 1; i <= n; i++) {
        int l = D.get_trans(seg[i].l), r = D.get_trans(seg[i].r), c = seg[i].c;


        TP center = query(1, l, r);
        if (center.first >= 2) cout << "0" << endl;
        else if (center.first == 1 && center.second.first != c) cout << "0" << endl;
        else {
            int ans = 1e9;
            ans = min(ans, qy(r + 1, _M, c, r, true));
            if (l > 1) ans = min(ans, qy(1, l-1, c, l, false));
            cout << ans << endl;
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