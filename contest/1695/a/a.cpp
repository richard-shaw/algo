/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-06-18 22:35:11
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
const int MAXN = 2e5 + 10;

int mp[41][41], tmp[41][41][41][41];
set<int> mx[41][41];
int dp(int i1, int j1, int i2, int j2) {
    if (i1 == i2 && j1 == j2) return mp[i1][j1];
    if (tmp[i1][j1][i2][j2] != -2e9) return tmp[i1][j1][i2][j2];
    int ans = mp[i2][j2];
    if (i2 > i1) ans = max(ans, dp(i1, j1, i2-1, j2));
    if (j2 > j1) ans = max(ans, dp(i1, j1, i2, j2-1));
    return tmp[i1][j1][i2][j2] = ans;
}
void solve(int _case) {
    /** Code here for each Case */
    int n, m, k = 2000;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> mp[i][j], mx[i][j].clear();
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) for (int I = i; I <= n; I++) for (int J = j; J <= m; J++) tmp[i][j][I][J] = -2e9;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) for (int I = i; I <= n; I++) for (int J = j; J <= m; J++) {
        int h = I - i + 1, w = J - j + 1;
        int ans = dp(i, j, I, J);
        mx[h][w].insert(ans);
    }
    for (int h = 1; h <= n; h++) for (int w = 1; w <= m; w++) if (mx[h][w].size() == 1) k = min(k, h * w);
    cout << k << endl;
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