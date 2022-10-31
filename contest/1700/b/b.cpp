/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-06-19 17:05:18
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
int ____MOD;
inline int fast_pow(int a, int b) { int base = a, ans = 1; while (b > 0) { if (b & 1) ans = (ans * base) % ____MOD; base = (base * base) % ____MOD; b >>= 1; } return ans; }
inline int inv(int b) { return fast_pow(b, ____MOD-2); }
inline int mod_mul(int a, int b) { return (a * b) % ____MOD; }
inline int mod_div(int a, int b) { return mod_mul(a, inv(b)); }

const int INF9 = 1e9 + 10;
const int INF18 = 1e18 + 10;
const int MOD = ____MOD = 998244353;
const int MAXN = 2e5 + 10;
int dig[MAXN];
string add(int L, string buf, int d2, int d1) {
    for (int i = 0; i < L; i++) dig[i] = buf[i] - '0';
    dig[L-1] += d1;
    dig[L-2] += d2;
    int pre = 0;
    for (int i = L - 1; i >= 0; i--) {
        int q = dig[i] + pre;
        if (q >= 10) pre = 1, dig[i] = q % 10;
        else pre = 0, dig[i] = q;
    }
    string ans = "";
    for (int i = 0; i < L; i++) ans += string(1, '0' + dig[i]);
    if (pre) return "1" + ans;
    else return ans;
}

void solve(int _case) {
    /** Code here for each Case */
    int n;
    string buf, ans = "";
    cin >> n >> buf;
    if (buf[0] != '9') {
        for (int i = 0; i < n; i++) {
            int k = '9' - buf[i];
            ans += to_string(k);
        }
    } else {
        ans = "1";
        for (int i = 1; i < n - 1; i++) {
            ans += to_string('9' - buf[i]);
        }
        if (buf[n - 1] == '0') {
            ans += "0";
            ans = add(n, ans, 2, 1);
        } else {
            ans += to_string('9' - buf[n - 1] + 1);
            ans = add(n, ans, 1, 1);
        }
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