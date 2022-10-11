/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: who_cuts_the_moonlight
 * Time: 2022-09-06 22:35:06
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


vector<int> E[MAXN];
map<string, int> EI;
queue<int> Q;
int _visit[MAXN], _color[MAXN];
pair<int, int> W[MAXN];
inline string __hash(int u, int v) {
    return to_string(u) + "_" + to_string(v);
}

void check(int n, int m) {
    if (n + 2 != m) return;
    set<int> p; p.clear();
    for (int i = 1; i <= m; i++) {
        if (_color[i] == 0) p.insert(W[i].first), p.insert(W[i].second);
    }
    if (p.size() != 3) return;
    int u = *p.begin(); p.erase(p.begin());
    int v = *p.begin(); p.erase(p.begin());
    int x = *p.begin(); p.clear();
    int F;

    if (E[u].size() > 2) {
        for (int f : E[u]) {
            if (f != v && f != x) {
                F = f;
                break;
            }
        }
    } else if (E[v].size()) {
        for (int f : E[v]) {
            if (f != u && f != x) {
                F = f;
                break;
            }
        }
    } else {
        for (int f : E[x]) {
            if (f != v && f != u) {
                F = f;
                break;
            }
        }
    }
    _color[EI[__hash(F, u)]] = 0;
    _color[EI[__hash(u, v)]] = 1;
}

void dfs(int u) {
    _visit[u] = 1;
    for (int v : E[u]) {
        if (!_visit[v]) {
            _color[EI[__hash(u, v)]] = 1;
            dfs(v);
        }
    }
}
void solve(int _case) {
    /** Code here for each Case */
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) E[i].clear(), _visit[i] = 0;
    EI.clear();

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        E[u].pb(v), E[v].pb(u);
        EI.insert({__hash(u, v), i}), EI.insert({__hash(v, u), i});
        _color[i] = 0;
        W[i].first = u, W[i].second = v;
    }

    for (int u = 1; u <= n; u++) {
        if (!_visit[u]) dfs(u);
    }

    check(n, m);

    for (int i = 1; i <= m; i++) cout << _color[i];
    cout << endl;
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