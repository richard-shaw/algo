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

int dig[MAXN];

vector<pair<int, int>> ans[2];
void solve(int _case) {
    /** Code here for each Case */
    int n; cin >> n;
    int c1 = 0, c0 = 0;
    string s;
    cin >> s;
    for (int i = 1; i <= 2*n; i++) {
        dig[i] = s[i-1]-'0';
        if (dig[i] == 1) c1++;
        else c0++;
    }


    if ((c1 & 1) || (c0 & 1)) { cout << -1 << endl; return; }
    ans[1].clear(), ans[0].clear();

    c0 = 0, c1 = 0;
    for (int i = 1; i <= 2*n; i++) {
        if (c0 == c1) ans[0].push_back({dig[i], i}), c0++;
        else {
            if (dig[i] == ans[0][c1].first) ans[1].push_back({dig[i], i}), c1++;
            else ans[0].push_back({ dig[i], i}), c0++;
        }
    }

    if (ans[0].size() == ans[1].size()) {
        cout << 0 << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[0][i].second;
            if (i < n - 1) cout << ' ';
            else cout << endl;
        }
    } else {
        int ed, st;
        if (c1 == 0) {
            for (int i = 1; i < c0; i++) {
                if (ans[0][i].first == ans[0][0].first) { ed = ans[0][i-1].second, st = ans[0][0].second; break; }
            }
        } else {
            for (int i = c1; i < c0; i++) {
                if (ans[0][i].first == ans[0][c1-1].first) { ed = ans[0][i-1].second, st = ans[0][c1-1].second; break; }
            }
        }
        cout << (ed - st + 1) << ' ';
        char q = s[st];
        for (int i = st; i < ed; i++) {
            s[i] = s[i+1];
            cout << i << ' ';
        }
        s[ed] = q;
        cout << ed << endl;


        ans[1].clear(), ans[0].clear();

        c0 = 0, c1 = 0;
        for (int i = 1; i <= 2*n; i++) {
            if (c0 == c1) ans[0].push_back({dig[i], i}), c0++;
            else {
                if (dig[i] == ans[0][c1].first) ans[1].push_back({dig[i], i}), c1++;
                else ans[0].push_back({ dig[i], i}), c0++;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[0][i].second;
            if (i < n - 1) cout << ' ';
            else cout << endl;
        }
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