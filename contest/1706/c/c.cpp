/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: who_cuts_the_moonlight
 * Time: 2022-07-18 22:35:08
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
const int MAXN = 1e5 + 10;
int h[MAXN];
pair<int, int> dp[MAXN][2];
void solve(int _case) {
    /** Code here for each Case */
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    dp[1][0] = {-1, INF18};
    dp[1][1] = {0, 0};
    dp[n][0] = {-1, INF18};
    for (int i = 2; i <= n; i++) {
        if (dp[i-1][0].first > dp[i-1][1].first) dp[i][1] = dp[i-1][0];
        else if (dp[i-1][0].first < dp[i-1][1].first) dp[i][1] = dp[i-1][1];
        else dp[i][1].first = dp[i-1][0].first, dp[i][1].second = min(dp[i-1][0].second, dp[i-1][1].second);
        if (i == n) continue;
        dp[i][0].first = dp[i-1][1].first + 1;
        dp[i][0].second = dp[i-1][1].second + max(0ll, max(h[i-1], h[i+1])+1-h[i]);
    }
    int c = dp[1][0].first, f = dp[1][1].second;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            if (dp[i][j].first > c) c = dp[i][j].first, f = dp[i][j].second;
            else if (dp[i][j].first == c) f = min(dp[i][j].second, f);
        }
    }
    cout << f << endl;
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