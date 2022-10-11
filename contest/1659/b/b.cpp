/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-04-17 22:35:06
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

vector<int> odd;
int cnt[MAXN];
void solve(int _case) {
    /** Code here for each Case */
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    odd.clear();
    for (int i = 1; i <= N; i++) {
        if (s[i-1] == '1' && K % 2 == 1) odd.pb(i);
        if (s[i-1] == '0' && K % 2 == 0) odd.pb(i);
    }
    for (int i = 1; i <= N; i++) cnt[i] = 0;
    if (K >= odd.size()) {
        if ((K-odd.size()) % 2 == 0) {
            for (int o : odd) cnt[o] = 1;
            cnt[1] += (K - odd.size());
        } else {
            for (int o : odd) cnt[o] = 1;
            cnt[1] += ((K-odd.size()) / 2) * 2;
            cnt[N] += 1;
        }
    } else {
        int k = K;
        for (int o : odd) {
            if (k > 0) cnt[o] = 1, k--;
        }
    }
    for (int i = 1; i <= N; i++) {
        if ((K-cnt[i]) % 2 == 1) s[i-1] = s[i-1] == '1' ? '0' : '1';
    }
    cout << s << endl;
    for (int i = 1; i < N; i++) cout << cnt[i] << ' ';
    cout << cnt[N] << endl;
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