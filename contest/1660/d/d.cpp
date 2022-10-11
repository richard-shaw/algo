/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-03-31 22:35:10
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
int arr[MAXN], N, count_neg[MAXN], count_2_[MAXN];
int lft_0[MAXN], rgh_neg[MAXN];

inline bool even_neg(int l, int r) { return (count_neg[r]-count_neg[l-1]) % 2 == 0; }
inline int count_2(int l, int r) { return count_2_[r] - count_2_[l-1]; }
void solve(int _case) {
    /** Code here for each Case */
    cin >> N;
    count_neg[0] = count_2_[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        count_neg[i] = count_neg[i-1] + (arr[i] < 0);
        count_2_[i] = count_2_[i-1] + (arr[i] == 2 || arr[i] == -2);
    }
    lft_0[N+1] = INF9, rgh_neg[0] = -1;
    for (int i = N; i >= 1; i--) {
        lft_0[i] = lft_0[i+1];
        if (arr[i] == 0) lft_0[i] = min(lft_0[i], i);
    }
    for (int i = 1; i <= N; i++) {
        rgh_neg[i] = rgh_neg[i-1];
        if (arr[i] < 0) rgh_neg[i] = max(rgh_neg[i], i);
    }

    int Ans = 0, L = 1, R = 0;
    for (int l = 1; l <= N; l++) {
        if (arr[l] == 0) continue;
        int r = lft_0[l+1] > 1e7 ? N : lft_0[l+1]-1;
        if (l > r) continue;
        if (even_neg(l, r)) {
            if (Ans < count_2(l, r)) {
                Ans = count_2(l, r);
                L = l;
                R = r;
            }
        } else {
            r = rgh_neg[r]-1;
            if (l > r) continue;
            if (Ans < count_2(l, r)) {
                Ans = count_2(l, r);
                L = l;
                R = r;
            }
        }
    }

    cout << (L-1) << ' ' << (N-R) << endl;
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