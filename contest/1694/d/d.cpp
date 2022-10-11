/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-06-16 22:35:59
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

int p[MAXN], L[MAXN], R[MAXN], N, V[MAXN];
bool ok[MAXN];
vector<int> order, E[MAXN];
queue<int> Q;
void dfs(int x, int u) {
    V[u] += x;
    ok[u] = V[u] <= R[u] && V[u] >= L[u];
    if (u == 1) return;
    int f = p[u];
    if (V[f] + x < L[f]) dfs(x, f);
    else if (V[f] + x <= R[f]) dfs(x, f);
    else dfs(R[f] - V[f], f);
}
void solve(int _case) {
    /** Code here for each Case */
    cin >> N;
    order.clear();
    memset(ok, 0, sizeof(ok));
    while(!Q.empty()) Q.pop();
    for (int i = 1; i <= N; i++) E[i].clear();
    for (int i = 2; i <= N; i++) cin >> p[i], E[p[i]].pb(i);
    for (int i = 1; i <= N; i++) cin >> L[i] >> R[i], V[i] = 0;
    Q.push(1);
    while (!Q.empty()) {
        int f = Q.front(); Q.pop();
        order.pb(f);
        for (int u : E[f]) Q.push(u);
    }
    reverse(order.begin(), order.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int u = order[i];
        if (ok[u]) continue;
        if (L[u] <= V[u] && V[u] <= R[u]) { ok[u] = true; continue; }
        ans++;
        int x = R[u] - V[u];
        dfs(x, u);
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