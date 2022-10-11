/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-07-04 22:35:01
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
const int MAXN = 5009;

int arr[MAXN];
vector<pair<bool, int>> V;
int SV(map<int, int> & mp) {
    multiset<int> XS; XS.clear();
    for (auto ite = mp.begin(); ite != mp.end(); ++ite) XS.insert(ite->second);
    while (XS.size() > 1) {
        auto f = XS.begin();
        auto e = prev(XS.end());
        int m = *f, M = *e;
        XS.erase(f), XS.erase(e);
        if (M != m) XS.insert(M - m);
    }
    return XS.empty() ? 0 : *XS.begin();
}
int sv(int base, int N) {
    V.clear();
    int c = 0;
    map<int, int> diff;
    diff.clear();
    for (int i = 1; i <= N; i++) {
        if (arr[i] == base) {
            if (c == 0) {
                V.pb({true, 1});
                c++;
            } else if (V[c-1].first) {
                V[c-1].second++;
            } else {
                V[c-1].second = SV(diff);
                diff.clear();
                V.push_back({true, 1});
                c++;
            }
        } else {
            if (c == 0) {
                V.push_back({false, 1});
                c = 1;
                diff.clear();
                diff.insert({arr[i], 1});
            } else if (!V[c-1].first) {
                if (diff.find(arr[i]) == diff.end()) diff.insert({arr[i], 1});
                else diff[arr[i]]++;
            } else {
                V.pb({false, 1});
                diff.clear();
                diff.insert({arr[i], 1});
                c++;
            }
        }
    }
    if (!diff.empty()) {
        V[c-1].second = SV(diff);
    }
    int x = 0, y = 0, K = V.size();
    for (int k = 0; k < K; k++) {
        if (V[k].first) {
            if (x > 0) {
                if (x > V[k].second) x -= V[k].second, V[k].second = 0;
                else V[k].second -= x, x = 0;
            }
            y += V[k].second;
        } else {
            if (y > 0) {
                if (y > V[k].second) y -= V[k].second, V[k].second = 0;
                else V[k].second -= y, y = 0;
            }
            x += V[k].second;
        }
    }
    return y;
}

set<int> QS;
vector<int> W;
void solve(int _case) {
    /** Code here for each Case */
    int N; cin >> N;
    QS.clear(), W.clear();
    for (int i = 1; i <= N; i++) cin >> arr[i], QS.insert(arr[i]);
    for (int qs : QS) W.pb(qs);
    int ans = 0;
    for (int i : W) {
        ans = max(ans, sv(i, N));
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