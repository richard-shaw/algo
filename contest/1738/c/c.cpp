/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: who_cuts_the_moonlight
 * Time: 2022-09-30 22:35:07
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


int tmp[103][103][2][2][2], target[2];
int dp(int n, int m, int s1, int s2, int k) {
    if (~tmp[n][m][s1][s2][k]) return tmp[n][m][s1][s2][k];
    int ans;
    if (n == 1) {
        if (m == 0) {
            if (k == 0) ans = (target[0] == s1) ? 0 : 1;
            else ans = (target[1] == s2) ? 1 : 0;
        } else {
            if (k == 0) ans = (target[0] == 1 - s1) ? 0 : 1;
            else ans = (target[1] == 1 - s2) ? 1 : 0;
        }
    } else {
        if (k ==0) {
            if (m > 0 && dp(n-1, m-1, 1-s1, s2, 1-k) == 0) ans = 0;
            else if (n > m && dp(n-1, m, s1, s2, 1-k) == 0) ans = 0;
            else ans = 1;
        } else {
            if (m > 0 && dp(n-1, m-1, s1, 1-s2, 1-k) == 1) ans = 1;
            else if (n > m && dp(n-1, m, s1, s2, 1-k) == 1) ans = 1;
            else ans = 0;
        }
    }
    return tmp[n][m][s1][s2][k] = ans;
}

void solve(int __) {
    int n, co = 0; cin >> n;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) for (int k1 = 0; k1 < 2; k1++) for (int k2 = 0; k2 < 2; k2++) for (int k3 = 0; k3 < 2; k3++) tmp[i][j][k1][k2][k3] = -1;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x & 1) co ++;
    }

    target[0] = 0, target[1] = (co & 1) ? 0 : 1;
    if (dp(n, co, 0, 0, 0) == 0) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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