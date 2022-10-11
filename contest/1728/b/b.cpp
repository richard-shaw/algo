/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: who_cuts_the_moonlight
 * Time: 2022-09-08 22:35:03
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


int tmp[103], ans[103];
void solve(int _case) {
    /** Code here for each Case */
    int n; cin >> n;
    int ans_s = -1;
    for (int i = 1; i <= n; i++) {
        deque<int> q;
        set<int> s;
        while (!q.empty()) q.pop_front();
        s.clear();
        q.push_back(i);
        for (int k = 1; k <= n; k++) if (k != i) s.insert(k);

        int sm = i;
        while (true) {
            auto ite = s.lower_bound(sm + 1);
            if (ite != s.end()) {
                bool ed = ite == prev(s.end());
                sm += *ite;
                q.push_back(*ite);
                s.erase(ite);
                if (ed) break;
            } else {
                sm += *s.rbegin();
                q.push_back(*s.rbegin());
                s.erase(prev(s.end()));
                break;
            }
        }
        int bn = s.size();
        for (int i = 1; i <= bn; i++) tmp[i] = *s.begin(), s.erase(s.begin());
        reverse(tmp + ((bn & 1) ? 2 : 1), tmp + 1 + bn);
        for (int i = bn; i >= 1; i--) q.push_front(tmp[i]);

        sm = 0;
        for (int i = 1; i <= n; i++) tmp[i] = q.front(), q.pop_front();
        for (int i = 1; i <= n; i++) {
            if (tmp[i] > sm) sm += tmp[i];
            else sm = 0;
        }

        if (ans_s < sm) {
            ans_s = sm;
            for (int i = 1; i <= n; i++) ans[i] = tmp[i];
        }
    }
    for (int i = 1; i < n; i++) cout << ans[i] << ' ';
    cout << ans[n] << endl;
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