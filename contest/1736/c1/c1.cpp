/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: who_cuts_the_moonlight
 * Time: 2022-10-10 22:35:07
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

int A[MAXN];
int d[MAXN][30], lg[MAXN];

int rmq(int l, int r) {
    if (l == r) return A[l];
    int ln = lg[r-l+1];
    return min(d[l][ln], d[r-(1<<ln)+1][ln]);
}
void solve(int _case) {
    /** Code here for each Case */
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i], A[i] -= i;

    for (int i = 1; i <= n; i++) d[i][0] = A[i];
    for (int j = 1; j < 30; j++) {
        for (int i = 1; i <= n; i++) {
            d[i][j] = d[i][j-1];
            if ((i+(1<<(j-1))) <= n) d[i][j] = min(d[i][j-1], d[i+(1<<(j-1))][j-1]);
        }
    }


    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n, target = - i + 1;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (rmq(i, m) >= target) l = m;
            else r = m;
        }
        if (l < r) if (rmq(i, r) >= target) l = r;
        if (i > l) continue;
        if (rmq(i, l) >= target) ans += (l - i + 1);
    }
    cout << ans << endl;
}

signed main() {
    memset(lg, 0, sizeof(lg));
    int pr = 2;
    for (int i = 1; i < 30; i++) {
        if (pr >= MAXN) break;
        int ed = min(MAXN, pr << 1);
        for (int j = pr; j < ed; j++) {
            lg[j] = i;
        }
        pr = ed;
    }
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