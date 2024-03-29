/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: who_cuts_the_moonlight
 * Time: 2022-09-12 22:35:08
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

int arr[MAXN];
vector<int> idx[9];
int pow10(int k) {
    int ans = 1, base = 10;
    while (k > 0) {
        if (k & 1) ans = (ans * base) % 9;
        base = (base * base) % 9;
        k >>= 1;
    }
    return ans;
}
int get_num(int l, int r) {
    if (l == 1) return arr[r];
    int k = (arr[r] - arr[l-1] * pow10(r - l + 1)) % 9;
    while (k < 0) k += 9;
    return k;
}

int xxxx(int x, int k) {
    for (int i = 0; i < 9; i++) {
        if ((x + i) % 9 == k) return i;
    }
}
void solve(int _case) {
    /** Code here for each Case */
    string buf; cin >> buf;
    int w, q; cin >> w >> q;

    int l0 = buf.size();
    int pr = 0;
    for (int i = 1; i <= l0; i++) {
        pr = (10 * pr + buf[i-1] - '0') % 9;
        arr[i] = pr;
    }

    for (int i = 0; i < 9; i++) idx[i].clear();
    for (int i = 1; i <= l0; i++) {
        if (i + w - 1 > l0) break;
        idx[get_num(i, i + w - 1)].push_back(i);
    }

    while (q--) {
        int l, r, k; cin >> l >> r >> k;

        int ansL = 1e9, ansR = 1e9;
        for (int L1 = 0; L1 < 9; L1++) {
            if (idx[L1].empty()) continue;
            int L11 = (L1 * get_num(l, r)) % 9;
            int L2 = xxxx(L11, k);
            if (idx[L2].empty()) continue;
            if (L1 == L2 && idx[L1].size() == 1) continue;
            int f1 = idx[L1][0];
            int f2 = (L1 == L2) ? idx[L1][1] : idx[L2][0];

            if (f1 < ansL) ansL = f1, ansR = f2;
            else if (f1 > ansL) continue;
            else if (f2 < ansR) ansR = f2;
        }
        if (ansL > l0) cout << "-1 -1" << endl;
        else cout << ansL << ' ' << ansR << endl;
    }


}

signed main() {

//    FAST_IO
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