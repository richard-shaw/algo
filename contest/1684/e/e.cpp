/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-05-19 22:35:08
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
//#define set(s) set<int> s; s.clear()
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
const int MAXN = 1e5 + 10;
int arr[MAXN];
set<int> tmp;
multiset<int> S, C;
int fun_(int n) {
    int mex = arr[n]+1;
    arr[0] = -1;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > arr[i-1] + 1) { mex = arr[i-1] + 1; break; }
    }
    tmp.clear();
    for (int i = 1; i <= n; i++) tmp.insert(arr[i]);
    return tmp.size() - mex;
}
void solve(int _case) {
    /** Code here for each Case */
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr+1, arr+1+n);
    if (k == 0) {
        cout << fun_(n) << endl;
        return;
    }

    int mex = arr[n]+1;
    arr[0] = -1;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > arr[i-1] + 1) { mex = arr[i-1] + 1; break; }
    }
    S.clear();
    C.clear();
    for (int i = 1; i <= n; i++) C.insert(arr[i]);
    for (int i = 1; i <= n; i++) {
        if (arr[i] > mex) S.insert(arr[i]);
    }

    while (k > 0 && S.size() > 0) {
        int _max = *S.rend();
        S.erase(S.find(_max));
        C.erase(C.find(_max));
        C.insert(mex);
        mex = mex + 1;
        k--;
        while (S.size() > 0 && (*S.begin() <= mex + 1)) {
            mex = mex + 1;
            S.erase(*S.begin());
        }
    }
    tmp.clear();
    for (auto num : C) tmp.insert(num);
    cout << tmp.size() - mex << endl;

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