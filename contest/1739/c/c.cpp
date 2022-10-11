/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: who_cuts_the_moonlight
 * Time: 2022-09-29 22:35:08
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
const int mod = 998244353;

int C[61][61], tmp[70][4][3];

int dp(int n, int s, int k) {
    if (~tmp[n][s][k]) return tmp[n][s][k];
    int ans = 0;
    if (n == 2) {
        ans = ((s == 1 && k == 1) || (s == 2 && k == 0)) ? 1 : 0;
    } else if (s == 0) {
        ans = k == 1 ? C[n-2][n>>1] : 0;
    } else if (s == 1) {
        ans = k == 1 ? C[n-2][(n>>1)-1] : 0;
    } else if (s == 3) {
        ans = k == 2 ? C[n-2][n>>1] : 0;
    } else {
        int ans1 = 0, ans2 = 0;
        for (int s0 = 0; s0 < 4; s0++) {
            ans1 = (ans1 + dp(n-2, s0, 2)) % mod;
            ans2 = (ans2 + dp(n-2, s0, 1)) % mod;
            if (k == 1) ans = ans1;
            else if (k == 2) ans = ans2;
            else ans = (C[n-2][(n>>1)-1] - ans1 - ans2) % mod;
        }
    }
    while (ans < 0) ans += mod;
    while (ans >= mod) ans -= mod;
    return tmp[n][s][k] = ans;
}

void solve(int _case) {
    /** Code here for each Case */
    int n; cin >> n;
    int a = 0, b = 0, d = 0;

    for (int s = 0; s < 4; s++) {
        a = (a + dp(n, s, 1)) % mod;
        b = (b + dp(n, s, 2)) % mod;
        d = (d + dp(n, s, 0)) % mod;
    }

    cout << a << ' ' << b << ' ' << d << endl;
}

signed main() {
    for (int i = 1; i <= 60; i++) C[i][i] = 1;
    for (int i = 1; i <= 60; i++) C[i][0] = 1;
    for (int i = 1; i <= 60; i++) for (int j = 1; j < i; j++) {
        C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    }
    for (int i = 0; i < 70; i++) for (int j = 0; j < 4; j++) for (int k = 0; k < 3; k++) tmp[i][j][k] = -1;
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