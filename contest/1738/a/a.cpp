/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: who_cuts_the_moonlight
 * Time: 2022-09-30 22:35:07
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

pair<int, int> magic[MAXN];
int fire[MAXN], frost[MAXN];
void solve(int _case) {
    /** Code here for each Case */
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> magic[i].first;
    for (int i = 1; i <= n; i++) cin >> magic[i].second;

    int c1 = 0, c2 = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (magic[i].first == 0) fire[++c1] = magic[i].second;
        else frost[++c2] = magic[i].second;
        ans += magic[i].second;
    }

    sort(fire + 1, fire + 1 + c1);
    sort(frost + 1, frost + 1 + c2);

    if (c1 == 0 || c2 == 0) {
        cout << ans << endl;
    } else if (c1 == c2){
        cout << (2 * ans - min(fire[1], frost[1])) << endl;
    } else {
        int k = min(c1, c2);
        for (int i = 1; i <= k; i++) {
            ans += fire[c1--];
            ans += frost[c2--];
        }
        cout << ans << endl;
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