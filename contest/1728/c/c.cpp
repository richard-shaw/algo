/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: who_cuts_the_moonlight
 * Time: 2022-09-08 22:35:03
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

int A[MAXN], B[MAXN];
multiset<int> sa, sb;
inline int LEN(int a) {
    if      (a >= 10 && a < 100) return 2;
    else if (a >= 100 && a < 1000) return 3;
    else if (a >= 1000 && a < 10000) return 4;
    else if (a >= 10000 && a < 100000) return 5;
    else if (a >= 100000 && a < 1000000) return 6;
    else if (a >= 1000000 && a < 10000000) return 7;
    else if (a >= 10000000 && a < 100000000) return 8;
    else                                      return 9;
}
void solve(int _case) {
    /** Code here for each Case */
    int n; cin >> n; sa.clear(), sb.clear();
    for (int i = 1; i <= n; i++) cin >> A[i], sa.insert(A[i]);
    for (int i = 1; i <= n; i++) cin >> B[i], sb.insert(B[i]);

    for (int i = 1; i <= n; i++) {
        if (A[i] < 10) continue;
        if (sb.find(A[i]) != sb.end()) {
            sa.erase(sa.find(A[i]));
            sb.erase(sb.find(A[i]));
        }
    }

    int ans = 0;
    int ca[10], cb[10];
    memset(ca, 0, sizeof(ca));
    memset(cb, 0, sizeof(cb));

    for (int a : sa) {
        if (a >= 10) ca[LEN(a)]++, ans++;
        else ca[a]++;
    }
    for (int b : sb) {
        if (b >= 10) cb[LEN(b)]++, ans++;
        else cb[b]++;
    }

    for (int i = 2; i <= 9; i++) ans += abs(ca[i] - cb[i]);
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